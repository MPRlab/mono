# discover_osc

Max patcher to aggregate MPR lab OSC discovery packets

## important objects

```
TODO: • patch these to external outlets, insert into other patchers as a subpatch
      • remove sender field, required because udprecieve strips headers
```

For each instrument that would like to be discovered on the network, they must each send an OSC packet over port 8000 that takes the form of:

```
/NoticeMe ["name of instrument", "IP address"]
```

Example:

```
/NoticeMe ["PVC", "10.0.0.5"]
```

The patcher collates each recieved packet, and allows the user to select a device. The IP address bound to each instrument is output as a message when an instrument is selected with the dropdown menu.
