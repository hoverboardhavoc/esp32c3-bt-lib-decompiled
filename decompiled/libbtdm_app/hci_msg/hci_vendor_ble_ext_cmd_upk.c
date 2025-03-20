/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> hci_msg.o -> hci_vendor_ble_ext_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_vendor_ble_ext_cmd_upk(int param_1,int param_2,ushort *param_3,uint param_4)

{
  int iVar1;
  int iStack_18;
  int aiStack_14 [2];
  
  if ((param_2 == 0) || (param_1 == 0)) {
    *param_3 = (ushort)param_4;
    iVar1 = 0;
  }
  else {
    iStack_18 = param_2;
    aiStack_14[0] = param_1;
    iVar1 = (**(code **)(_r_ip_funcs_p + 0xa4))
                      (&iStack_18,aiStack_14,param_2 + param_4,(uint)*param_3 + param_1,
                       param_4 & 0xff,*(code **)(_r_ip_funcs_p + 0xa4));
    if (iVar1 == 0) {
      *param_3 = (short)aiStack_14[0] - (short)param_1;
    }
  }
  return iVar1;
}

