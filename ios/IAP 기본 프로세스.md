# IAP 기본 프로세스

# 인-앱 구매 상품들 나열하기

- 인-앱 결제 상품들의 full Product ID 의 Set으로 `SKProductsRequest` 객체를 만듭니다.

```objectivec
NSSet<NSString *> * productIdentifiers = [NSSet setWithArray: @[@"com.smart.product1", @"com.smart.product2", @"com.smart.product3"]];
SKProductsRequest *productsRequest = [[SKProductsRequest alloc] initWithProductIdentifiers: productIdentifiers];
```

```swift
let productIdentifiers: Set<String> = []
let productsRequest = SKProductsRequest(productIdentifiers: productIdentifiers)
```

- IAPManager를 `SKProductsRequestDelegate` 를 채택하도록 하고 `SKProductsRequest` 객체의 `start` 메소드를 호출시켜 앱스토어에 request를 보냅니다.

```objectivec
//IAPHelper.h
@interface IAPHelper : NSObject <SKProductsRequestDelegate>

//IAPHelper.m
@implementation IAPHelper

- (void)requestFunctionExample 
{
    NSSet<NSString *> *productIdentifiers = [NSSet setWithArray: @[@"com.smart.product1", @"com.smart.product2", @"com.smart.product3"]];
    SKProductsRequest *productsRequest = [[SKProductsRequest alloc] initWithProductIdentifiers: productIdentifiers];
    productsRequest.delegate = self;
    [productsRequest start];
}
```

```swift
class IAPManager: SKProductsRequestDelegate {}

extension IAPManager {
	func requestFunctionExample() {
		let productIdentifiers: Set<String> = []
		let productsRequest = SKProductsRequest(productIdentifiers: productIdentifiers)								
		productsRequest.delegate = self
		protuctsRequest.start()
	}
}
```

- AppStore로부터의 응답을 IAPManager가 Delegate로서 받습니다. 성공적으로 받는 경우 `productsRequest(_ request: SKProductsRequest, didReceive response: SKProductsResponse)` 가 호출되고, request가 실패한 경우 `request(_ request: SKRequest, didFailWithError error: Error)` 가 호출됩니다. ( 두 메소드 모두 delegate를 채택하면 구현해야함)
성공한 경우, 받은 `[SKProduct]` 배열로 뷰에 상품을 나열하면 됩니다.

```objectivec
//success
- (void)productsRequest:(nonnull SKProductsRequest *)request didReceiveResponse:(nonnull SKProductsResponse *)response
{
    NSLog(@"Loaded list of products...");
    NSArray<SKProduct *> *products = [response products];
    
    for (SKProduct *product in products)
    {
        NSLog(@"Found Product: %@ %@ %f", [product productIdentifier], [product localizedTitle], [[product price] floatValue]);
    }
}

//fail
- (void)request:(SKRequest *)request didFailWithError:(NSError *)error
{
    NSLog(@"%@", [error localizedDescription]);
}
```

```swift
//success
public func productsRequest(_ request: SKProductsRequest, didReceive response: SKProductsResponse) {
    print("Loaded list of products...")
    let products: [SKProduct] = response.products
    for product in products {
      print("Found product: \(product.productIdentifier) \(product.localizedTitle) \(product.price.floatValue)")
    }
}

//fail
public func request(_ request: SKRequest, didFailWithError error: Error) {
    print("Error: \(error.localizedDescription)")
}
```

# 인앱 구매 상품 구매 기능

- 미리 IAPManger가 `SKPaymentTransactionObserver` 를 채택하고 `paymentQueue(_ queue: SKPaymentQueue, updatedTransactions transactions: [SKPaymentTransaction])`를 구현하게 합니다.

```objectivec
// IAPHelper.h
@interface IAPHelper : NSObject <SKPaymentTransactionObserver>

// IAPHelper.m
- (void)paymentQueue:(nonnull SKPaymentQueue *)queue updatedTransactions:(nonnull NSArray<SKPaymentTransaction *> *)transactions {
    // ...
}
```

```swift
class IAPManager: SKPaymentTransactionObserver {
	paymentQueue(_ queue: SKPaymentQueue, updatedTransactions transactions: [SKPaymentTransaction])	{
		//...
	}
}
```

- IAPManager를 `SKPaymentQueue` 에 add해서 observer로서 등록합니다.

```objectivec
- (instancetype)init
{
    self = [super init];
    if (self) {
        [[SKPaymentQueue defaultQueue] addTransactionObserver: self];
    }
    return self;
}
```

```swift
SKPaymentQueue.default().add(self)
```

- 사용자가 구매 버튼을 누르면 해당 `SKProduct` 객체로 `SKPayment` 를 만듭니다.

```objectivec
SKPayment *payment = [SKPayment paymentWithProduct: product];
[[SKPaymentQueue defaultQueue] addPayment: payment];
```

```swift
let payment = SKPayment(product: product)
SKPaymentQueue.default().add(payment)
```

- `SKPayment` 객체를 `SKPaymentQueue` 에 add 합니다. SKPayment 객체를 add 할때마다, 큐는 payment 를 처리하기 위해 `SKPaymentTransaction` 객체를 생성하고 `SKPaymentTransaction` 객체가 처리되도록 대기열에 넣습니다.
- payment(결제)가 완전히 이행되면, 큐는 transaction 객체를 업데이트하고, 이 업데이트된 transaction 객체를 `SKPaymentTransactionObserver`인 IAPManager객체에게 보냅니다(send).
- IAPManager는 transaction 객체를 큐로 부터 받으면 state(`purchased`, `restore`, `failed` )에 맞게 transaction 객체를 처리하고 `finishTransaction` 메소드를 호출시켜 트랜젝션을 완료시키고, 큐에도 해당 `Transaction` 객체를 제거합니다.

```objectivec
- (void)paymentQueue:(nonnull SKPaymentQueue *)queue updatedTransactions:(nonnull NSArray<SKPaymentTransaction *> *)transactions {
    for (SKPaymentTransaction *paymentTransaction in transactions)
    {
        switch ([paymentTransaction transactionState]) {
            case SKPaymentTransactionStatePurchased:
                [self complete: paymentTransaction];
                break;
            case SKPaymentTransactionStateFailed:
                [self fail: paymentTransaction];
                break;
            case SKPaymentTransactionStateRestored:
                [self restore: paymentTransaction];
                break;
            case SKPaymentTransactionStateDeferred:
                break;
            case SKPaymentTransactionStatePurchasing:
                break;;
        }
    }
}
```

```objectivec
- (void)complete:(nonnull SKPaymentTransaction *) transaction
{
    [self deliverPurchaseNotificationFor: [[transaction payment] productIdentifier]];
    [[SKPaymentQueue defaultQueue] finishTransaction: transaction];
}
```

```swift
//Just Example 
public func paymentQueue(_ queue: SKPaymentQueue, updatedTransactions transactions: [SKPaymentTransaction]) {
    for transaction in transactions {
      switch (transaction.transactionState) {
      case .purchased:
        complete(transaction: transaction)
        break
      case .failed:
        fail(transaction: transaction)
        break
      case .restored:
        restore(transaction: transaction)
        break
      case .deferred:
        break
      case .purchasing:
        break
      }
    }
}
```

```swift
//Just Example 
private func complete(transaction: SKPaymentTransaction) {
    print("complete...")
    deliverPurchaseNotificationFor(identifier: transaction.payment.productIdentifier)
    SKPaymentQueue.default().finishTransaction(transaction) 
    // finishTransaction을 호출해 트랜젝션을 완료시키고, 큐에서 transaction 객체를 제거시킨다. 
}
```

# 구매 기록 복원하기

`복원` 버튼을 누르면 아래 코드처럼 `SKPaymentQueue` 객체를 이용해 구매 기록들을 복원합니다.  그 이후에 IAPManager가 Observer로서 복원 상태(`.restored`)의 `SKPaymentTransaction`객체를 처리하면 됩니다.

```objectivec
[[SKPaymentQueue defaultQueue] restoreCompletedTransactions];
```

```swift
SKPaymentQueue.default().restoreCompletedTransactions()
```

# 상품 구매 Permissions

특정 유저의 폰이나 계정은 구매가 허가되지 않습니다. 예를 들어, 부모가 아이의 폰이나 계정을 구매 불가하는 경우입니다. 애플은 이 상황을 매우 아름답게 구현시켰습니다.  `SKPaymentQueue.canMakePayments()` 의 (Bool)값이 `true`이면 구매 가능한 앱/계정이고, `false`이면  구매 가능하지 않은 앱/계정입니다. 따라서 이 값에 따라 구매 상품의 구매 유무를 표시하십시오.

```objectivec
[SKPaymentQueue canMakePayments];
```

```swift
SKPaymentQueue.canMakePayments()
```