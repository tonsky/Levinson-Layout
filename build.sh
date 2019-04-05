#!/bin/bash
set -ev

iconutil --convert icns --output Levinson.bundle/Contents/Resources/English\ -\ Levinson.icns English.iconset
iconutil --convert icns --output Levinson.bundle/Contents/Resources/Russian\ -\ Levinson.icns Russian.iconset

touch Levinson.bundle

sudo rm -rf /Library/Keyboard\ Layouts/Levinson.bundle
sudo cp -r Levinson.bundle /Library/Keyboard\ Layouts/