git clone https://gitlab.com/nsnam/ns-3-dev.git ns3
cd ns3
git checkout -b ns-3.44-branch ns-3.44
cp -rf ../submission/* ./

./refresh.bash
./test.py
./ns3 run first
