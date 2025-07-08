#!/bin/bash

if ! openssl version ; then
    echo "Failed to get OpenSSL version, please check if it's installed."
    exit
fi

echo ""
echo "Generating self signed certificate..."

openssl req -x509 -nodes -newkey rsa:2048 -sha256 -keyout private-key.pem -out certificate.pem -days 365 -subj "/CN=localhost"
