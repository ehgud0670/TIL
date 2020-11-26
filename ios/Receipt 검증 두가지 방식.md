# Receipt 검증 두가지 방식

[Apple Developer Documentation](https://developer.apple.com/documentation/storekit/in-app_purchase/choosing_a_receipt_validation_technique?language=objc)

[[ IAP ] 5. Validating Purchases](https://eunjo-princess.tistory.com/20)

## Overview

- App Store receipt는 앱 구입 또는 앱 내에서 이루어진 구매 기록을 제공하며, receipt validation code를 앱(로컬) 또는 서버에 추가하여 구매한 콘텐츠를 인증할 수 있다. 영수증 유효성 검사를 수행하려면 애플리케이션에 고유한 보안 솔루션을 사용하기 위해 **보안 코딩 기술(로컬 or 서버 사이드)**을 이해해야한다.

## Choose a Validation Technique

영수증의 유효성을 검증하는데 두 가지 방법이 있다.

- 로컬 기기 내 영수증 확인 - 인앱 구매가있는 앱의 영수증 서명을 확인하는 데 권장된다.
- App Store를 통한 서버 측 영수증 확인 - 구매 기록 유지 및 관리를 위해 앱 내 구매를 유지하는 데 권장된다.

Compare the approaches and determine the best fit for your app and your infrastructure. You can also choose to implement both approaches.

- Consumable in-app purchases 는 `finishTransactin` 메소드가 호출할 때까지만 영수증 기록에 남아있으므로 Consumable in-app purchases 의 기록을 남기고싶다면 서버로 유지하고 관리하라.
- Non-consumables 상품, auto-renewing subscription 상품, non-renewing subscription 상품들은 영수증에 영원히 기록된다.
- 자동 갱신 구독 서비스의 경우, 서버사이드 영수증 검증 방식이 디바이스 검증 방식보다 주요 장점들을 제공해준다.

[자동 갱신 구독 서비스 할 때 디바이스 검증 방식 vs 서버 사이드 검증 방식](https://www.notion.so/9b5dea18ad504614b05b64e54a2fb8cd)

⇒ 서버 검증 방식이 훨씬 유리하다.

> Note 
renewal transactions(갱신)을 포함한 온-디바이스 영수증 검증 방식을 위해선 영수증을 업데이트(refresh)하기 위해 인터넷 연결을 해야만 한다.

## Verify Receipts

- 로컬에서 영수증을 검증하려면 PKCS #7 시그니처를 읽고 검증하는 코드가 필요하며, 서명된 페이로드를 파싱하고 검증하는 코드가 필요하다. 
App Store 를 통해 검증하려면 앱과 서버간의 보안 연결이 필요하며, 서버에 AppStore를 통한 영수증 검증 코드가 있어야 한다.
- 일반적으로, 영수증은 구매가 완료됐거나 복구된 직후에 업데이트되지만, 앱이 실행 중이 아닐 때 변경사항이 발생할 수 있다. 필요한 경우 `SKReceiptRefreshRequest` 를 호출하여, 백그라운드에서 구독이 갱신되는 경우 등 사용 중인 영수증이 최신인지 확인해야 한다. 이 refresh 는 네트워크 연결을 요구한다.