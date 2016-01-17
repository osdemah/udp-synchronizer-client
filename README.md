# udp-synchronizer-client 0.1

**Send orders from client to server. Orders could be any of create/remove file and create/remove folder.**

## set up

####build
    cmake .
    make

####run

to send orders from client to server you should provide following arguments:

* host (name/IP) address
* port number
* event name (any of CREATE_FILE, CREATE_DIR, REMOVE_FILE, REMOVE_DIR)
* file/folder name

example:

    ./udp_synchronizer_client 192.168.124.167 8000 CREATE_FILE ~/Pictures/screenshot1.jpg

### contact information

* @hamed1soleimani
* hamed1soleimani@gmail.com
