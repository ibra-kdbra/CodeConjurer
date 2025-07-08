@ECHO OFF

openssl version > nul

IF NOT %ERRORLEVEL% == 0 (
    ECHO Failed to get OpenSSL version, please check if it's installed.
    EXIT /B %ERRORLEVEL%
)

openssl req -x509 -nodes -newkey rsa:2048 -sha256 -keyout private-key.pem -out certificate.pem -days 365 -subj "/CN=localhost"

IF NOT %ERRORLEVEL% == 0 (
    ECHO Failed to generate self signed certificate.
    EXIT /B %ERRORLEVEL%
)

EXIT /B 0
