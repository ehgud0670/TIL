# In-App Receipt Fields

## Quantity

: 구매한 item의 개수.

```markdown
ASN.1 Field Type: 1701
ASN.1 Field Value: INTEGER 
JSON Field Name: quantity
JSON Field Value: string, interpreted as an integer
```

: 이 값은 transaction의 payment 프로퍼티에 저장된 `SKPayment` 객체의 quantity 프로퍼티와 값이 일치한다.

## Product Identifier

: 구매한 아이템의 product identifier.

```markdown
ASN.1 Field Type: 1702
ASN.1 Field Value: UTF8String
JSON Field Name: product_id
JSON Field Value: string
```

: 이 값은 transaction의 payment 프로퍼티에 저장된 `SKPayment` 객체의 productIdentifier 프로퍼티와 값이 일치한다.

## Transaction Identifier

: The transaction identifier of the item that was purchased.

```markdown
ASN.1 Field Type: 1703
ASN.1 Field Value: UTF8String
JSON Field Name: transaction_id
JSON Field Value: string
```

:  이 값은 tranction의 transactionIdentifer 프로퍼티와 일치한다. 

: 이전의 transaction을 복구한 transaction의 경우에는, 이 값은 original purchase transaction 의 transaction identifier 와 값이 다르다. 자동 갱신 구독 영수증의 경우에는, transaction identifier 의 새 값이 구독이 새로 갱신되거나 새로운 디바이스에서 복원됐을 때 매번 생성(generated) 된다. 

## Original Transaction Identifier

: 이전 transaction을 복원하는 transaction의 경우, original transaction의 transaction identifier 입니다. 
그렇지 않으면, transaction identifier 와 동일합니다.

```markdown
ASN.1 Field Type: 1705 
ASN.1 Field Value: UTF8String
JSON Field Name: original_transaction_id
JSON Field Value: string
```

: 이 값은 original transaction의 `transactionIdentifier` property와 값이 동일합니다.

: 이 값은 **특정 구독에 대해 생성된 모든 영수증에 대해 동일**합니다. 이 값은 동일한 개별 고객의 구독에 대한 여러 iOS 6 스타일 transaction receipt를 함께 연결하는 데 유용합니다.

## Purchase Date

: 상품을 구매한 날짜와 시간

```markdown
ASN.1 Field Type: 1704 
ASN.1 Field Value: IA5String, interpreted as an RFC 3339 date
JSON Field Name: purchase_date
JSON Field Value: string, interpreted as an RFC 3339 date
```

: 이 값은 transaction의 `transactionDate` 프로퍼티의 값과 일치합니다.

: 이전 거래를 복원하는 거래의 경우, 구매 날짜는 original 구매 날짜와 동일합니다. `Original Purchase Date`를 사용하여 original 거래 날짜를 확인하십시오.

: 자동 갱신 구독 영수증에서 구매 날짜는 구독을 구매하거나 **갱신한** 날짜입니다 (소멸 여부에 관계없이). 현재 기간 만료일에 자동 갱신되는 경우 구매 일은 현재 기간의 종료일과 동일한 **다음 기간의 시작일**입니다.

## Original Purchase Date

: 이전 트랜잭션을 복원하는 트랜잭션의 경우 원래 트랜잭션 날짜입니다.

```markdown
ASN.1 Field Type: 1706 
ASN.1 Field Value: IA5String, interpreted as an RFC 3339 date
JSON Field Name: original_purchase_date
JSON Field Value: IA5String, interpreted as an RFC 3339 date
```

## Subscription Expiration Date

: The expiration date for the subscription, expressed as the number of milliseconds since January 1, 1970, 00:00:00 GMT.

```markdown
ASN.1 Field Type: 1708
ASN.1 Field Value: IA5String, interpreted as an RFC 3339 date 
JSON Field Name: expires_date
JSON Field Value: IA5String, interpreted as an RFC 3339 date
```

## Subscription Expiration Intent

: For an expired subscription, the reason for the subscription expiration.

```markdown
ASN.1 Field Type: (none) 
ASN.1 Field Value: (none)
JSON Field Name: expiration_intent
JSON Field Value: string, interpreted as an integer
```

"1": customer cancellation, "2": billing error, ex. payment invalid, "3": customer did not agree increment, "4": product is not available, "5": unknown error

## Subscription Retry Flag

: For an expired subscription, whether or not Apple is still attempting to automatically renew the subscription.

```markdown
ASN.1 Field Type: (none) 
ASN.1 Field Value: (none)
JSON Field Name: is_in_billing_retry_period
JSON Field Value: string, interpreted as an integer
```

"1": retry , "0": no retry

## Subscription Trial Period

: For a subscription, whether or not it is in the free trial period.

```markdown
ASN.1 Field Type: (none)  
ASN.1 Field Value: (none)
JSON Field Name: is_trial_period
JSON Field Value: string
```

true / false

## Subscription Introductory Price Period

: For an auto-renewable subscription, whether or not it is in the introductory price period.

```markdown
ASN.1 Field Type: 1719 
ASN.1 Field Value: INTEGER
JSON Field Name: is_in_intro_offer_period
JSON Field Value: string 
```

true / false

## Cancellation Date

: For a transaction that was canceled by Apple customer support, the time and date of the cancellation. For an auto-renewable subscription plan that was upgraded, the time and date of the upgrade transaction.

```markdown
ASN.1 Field Type: 1712
ASN.1 Field Value: IA5String, interpreted as an RFC 3339 date
JSON Field Name: 
JSON Field Value: string, interpreted as an RFC 3339 date
```

## Cancellation Reason

: For a transaction that was canceled, the reason for cancellation.

```markdown
ASN.1 Field Type: (none)  
ASN.1 Field Value: (none)
JSON Field Name: cancellation_reason
JSON Field Value: string, interpreted as an Integer
```

"1":  not accidentally

"0": accidentally

## App Item ID

: A string that the App Store uses to uniquely identify the application that created the transaction. 

```markdown
ASN.1 Field Type: (none) 
ASN.1 Field Value: (none)
JSON Field Name: app_item_id
JSON Field Value: string
```

## External Version Identifier

: An arbitrary number that uniquely identifies a revision of your application.

```markdown
ASN.1 Field Type: (none)
ASN.1 Field Value: (none)
JSON Field Name: version_external_identifier
JSON Field Value: string
```

## Web Order Line Item ID

: The primary key for identifying subscription purchases.

```markdown
ASN.1 Field Type: 1711
ASN.1 Field Value: INTEGER
JSON Field Name: web_order_line_item_id
JSON Field Value: string
```

## Subscription Auto Renew Status

: The current renewal status for the auto-renewable subscription.

```markdown
ASN.1 Field Type: (none)  
ASN.1 Field Value: (none)
JSON Field Name: auto_renew_status
JSON Field Value: string, interpreted as an integer
```

"1": will renew
"0": not renew

## Subscription Auto Renew Preference

: The current renewal preference for the auto-renewable subscription.

```markdown
ASN.1 Field Type: (none)  
ASN.1 Field Value: (none)
JSON Field Name: auto_renew_product_id
JSON Field Value: string
```

## Subscription Price Consent Status

: The current price consent status for a subscription price increase.

```markdown
ASN.1 Field Type: (none)
ASN.1 Field Value: (none)
JSON Field Name: price_consent_status
JSON Field Value: string, interpreted as an integer
```

"1": customer agree increment

"0": customer no action about agree increment