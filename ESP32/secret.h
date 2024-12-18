#ifndef SECRET_H
#define SECRET_H

#include <pgmspace.h>

// WiFi credentials
const char WIFI_SSID[] = "TP-LINK_IoT";
const char WIFI_PASSWORD[] = "@Lexander_fc21";

// AWS IoT Core endpoint
const char AWS_IOT_ENDPOINT[] = "av523msmpxypp-ats.iot.eu-central-1.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAKe7v/tpD55V8gl1ccX62qO+YygUMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yNDExMjAxMTQ1
MThaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC0+rQQ82IfnCI2A3LT
HwfYmXrTY8eD1s3uyVql8OW+438HSv44irq7BiG69kWSfz0VtxHWD238nTLMp+Yf
UhPPuBTwY/ihmT6Y6KfsPXmlqXdGMUrtAyftyRvbvCZEiTuR5Y2i9Axpe1TK4dvP
lEtvH87N+HkRMK0aKEH6/BzNA12e+NqbJm3931f8ZI8/cwUumqDOJ2MSS62+lljx
ATELyhxkq88A4dGSLjfZvv2QdbPmbf91oduBzIdawFcKPqc/Pwh5cGUjek+yklth
3/XLKFWHSCcZqrXu6N1RXQo+CORwzAhIsLvjRKCtdhKTBxPogjtXVzU5Zxqbe8f7
rw1FAgMBAAGjYDBeMB8GA1UdIwQYMBaAFJNupqBiO5QMIDCvcBP5nTlryr3XMB0G
A1UdDgQWBBSPGSkSBnXb7Tk4pZZvBlUuKFj8NjAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEApIoeKk8rTWqC3Q9B7CMjDmYb
diJrqQzTU71MCFsdChOfJd6ajqJCLTkwtU+joTPDax4tmxmHW9ARxJ0i3xiFR09p
vte+7ZwWD0dLIRb7bLCRxO/2zPeYTMe3ZrZg8Fgf1I2TaobJCQEbL4rUTxemygoT
MYh7gm3cWzS6dwo+AJcnINkzl2pHPQDDDr0pkysw8bsnMv4ZaFmETrS7MgoO6KXO
1jraCKJgcYph6/Bt8V4Go9OljlE8FISfRDYLj/mlmyjNh0RtHse9q1opBCwsD7Vs
3EXm+tz9TsqiFPCT2IXp/8k0KWB5P/cUpvSV+6uWsjLwgKMCP3gGp+h42Jb61Q==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAtPq0EPNiH5wiNgNy0x8H2Jl602PHg9bN7slapfDlvuN/B0r+
OIq6uwYhuvZFkn89FbcR1g9t/J0yzKfmH1ITz7gU8GP4oZk+mOin7D15pal3RjFK
7QMn7ckb27wmRIk7keWNovQMaXtUyuHbz5RLbx/Ozfh5ETCtGihB+vwczQNdnvja
myZt/d9X/GSPP3MFLpqgzidjEkutvpZY8QExC8ocZKvPAOHRki432b79kHWz5m3/
daHbgcyHWsBXCj6nPz8IeXBlI3pPspJbYd/1yyhVh0gnGaq17ujdUV0KPgjkcMwI
SLC740SgrXYSkwcT6II7V1c1OWcam3vH+68NRQIDAQABAoIBAC3RiuT/uUfnb4Hd
PaTVplbgBIigKlLmfxyFPb3lT0UUs4RVKCeId94Bn2iGEPcV35Ev2AQpw97AravC
ljA3x2w/Xo29waSn94Ee5eSZa8LVNK1ArYdz1RgOYk8vQ0D2vW4if8lRoBLUdpMm
u0/Ca5ampuTek0gW2rxUlN/GFESSuIcuMM//HuJm7Ad+zReQoIuSKJmi3Vk5ncuB
YA6h9xAe4TESbNE2NItNldbnT3eof1RcIaaEfY7hgrAxjFy4DKmYWSzaqXBiRgLX
WTebCEs67BGY8ZjOWsI+Z5MzFY2FeMrhtwgIYEGOX6dwD7ign4bIfzg3KQKsFtj1
jcodKAECgYEA3dXhxGC97TWhgdRpssdXo9V5FkIXsNWaQwApJkkxF2oD+tkqLb6i
GTF/fVfXGdoabc88iaJRHI7kOD1b4TCMp+U1+KrmN5/r8Rc8yhsbB7Gw0E1QJwCX
Ia5rNAELV1hXtBscn/UBnPfvXND1mVt3abht/yiy9v7j7FJuR/BYTiECgYEA0NoF
MGyF5boUola3pJRI7OLXK5GP9XHom0wj8nhiKCoy+op2jbNEUmYUqqOGCEOwFn50
BXXnw9WLdpZKl7KfVnhSlcZVf4zBnndVInMjumhqE7jHz+6dxOASXrxILtCJ1va5
/kVf/uuZ4AmuxhrrX4UfvsNnP47cpXGYIny6cqUCgYBApCdyiuItMhiK9XOLZe0S
z4zGQKIYpFWcOnrDLkbA1OKuAQP6andfsf29b5A9d0GGSAIS9Rp/oN+9x5tzZitG
bVMpz9rf0Jj3Gtda6UUaG9wzBqRZiSGA7gtNDxTX8eU0lUXlEobSz6iPOlCmzHFi
fByJYrmroaCW53o9OjrxIQKBgQCiXo2gOw7SLhvypeZ6Dkqv2B+eoLlCAf/sFILx
9EOjpEMj41gODCv2v6QbkawXasBQjJkY0bSQ3MljNa7iRx13dW4HQT2hP0YcM/w9
HzTMrHajxImbj5CayfWeL1UTCE/RjtnE5BygrHxh4EU/gRgyl+W5QmNX13KVMT4s
ubmefQKBgEnQ5ZFUEAYvprDQboy5wPQzeVIIKIYoO4tgSjZRUzQEK6//QeBuGsG/
9tMOaT5Hgqp4mGVKRj2JWudwFmM/sMnznO/gJ6g5t4hSaJgD3d3XZ/moDIDjpeba
iDQOwvQQRoW1eDOIIHNTaNt4rozjjGCPSWEwMdcqiV44arMfoRlB
-----END RSA PRIVATE KEY-----
)KEY";

#endif // SECRET_H
