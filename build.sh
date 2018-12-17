#!/bin/bash
set -ev

iconutil --convert icns --output Levinson.bundle/Contents/Resources/English\ -\ Levinson.icns English\ Light.iconset
iconutil --convert icns --output Levinson.bundle/Contents/Resources/Russian\ -\ Levinson.icns Russian\ Light.iconset
# iconutil --convert icns --output Levinson.bundle/Contents/Resources/English\ -\ Levinson\ Dark.icns English\ Dark.iconset
# iconutil --convert icns --output Levinson.bundle/Contents/Resources/Russian\ -\ Levinson\ Dark.icns Russian\ Dark.iconset

touch Levinson.bundle

rm -rf ~/Library/Keyboard\ Layouts/Levinson.bundle
cp -r Levinson.bundle ~/Library/Keyboard\ Layouts/