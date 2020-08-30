출처: <https://developer.apple.com/documentation/foundation/archives_and_serialization/encoding_and_decoding_custom_types>

# Encoding and Decoding Custom Types

JSON과 같은 외부 표현과의 호환성을 위해 데이터 유형을 인코딩 및 디코딩 할 수 있게 하십시오.

## Overview

많은 프로그래밍 작업에는 **네트워크 연결을 통한 데이터 전송, 디스크에 데이터 저장, 또는 API나 서비스에 데이터 전송 등의 작업들**이 포함됩니다. **(인코딩 및 디코딩을 해야하는 작업들!)**
이러한 작업들은 데이터가 전송되는 동안 데이터가 **중간 형식으로 인코딩 및 디코딩**해야 합니다.

스위프트 표준 라이브러리는 데이터 인코딩 및 디코딩에 대한 표준화된 접근 방식을 정의합니다.
당신의 custom 타입에 Encodable 및 Decodable 프로토콜을 구현하여 이 방법을 채택하면 됩니다. 
이 프로토콜을 채택하면 Encoder 및 Decoder 프로토콜 구현에서 데이터를 가져와 JSON 또는 프로퍼티 리스트(가 뭐지?)과 같은 외부 표현으로 데이터를 인코딩하거나 디코딩 할 수 있습니다.(굉장하다) 
인코딩과 디코디을 모두 지원하려면, Codable에 적합성(conformance)을 선언하십시오, Codable은 Encodable 프로토콜과 Decodable 프로토콜을 결합한 형태입니다. 이 과정은 당신의 타입을 codable하게 만드는 것으로 알려져 있습니다. 
