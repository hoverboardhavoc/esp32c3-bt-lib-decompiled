/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_msg.o -> hci_vendor_ble_ext_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint hci_vendor_ble_ext_cmd_upk(int param_1,int param_2,ushort *param_3,uint param_4)

{
  uint uVar1;
  int iStack_18;
  int aiStack_14 [2];
  
  if ((param_2 == 0) || (param_1 == 0)) {
    *param_3 = (ushort)param_4;
    uVar1 = 0;
  }
  else {
    iStack_18 = param_2;
    aiStack_14[0] = param_1;
    uVar1 = r_hci_pack_bytes(&iStack_18,aiStack_14,param_4 + param_2,(uint)*param_3 + param_1,
                             param_4 & 0xff);
    if (uVar1 == 0) {
      *param_3 = (short)aiStack_14[0] - (short)param_1;
    }
  }
  return uVar1 & 0xffff;
}

