#!bin/bash
# clear
cd src

gcc main.c -o treasure

cp treasure ../bin/exe/
cp treasure ../bin/install/treasurecli
rm treasure

echo "BUILD COMPLETED"
# clear

# only for testing
cd ../bin/exe

# creating a virtual environment
mkdir tmp
cp treasure ./tmp
cd tmp
ls

./treasure

# deleting the virtual environment
cd ..
rm -rf tmp
echo "Deleting the Temporary Space..."
