/*
 * Last changed at upstream commit 76ed4114ee7d081435a3c65793b4c8eb1dfaf199
 * https://github.com/espressif/esp32c3-bt-lib/commit/76ed4114ee7d081435a3c65793b4c8eb1dfaf199
 * Upstream date: 2024-04-09 17:28:48 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(c23ab4c)
 * Source: libbtdm_app -> hci_msg.o -> hci_vendor_ble_qa_test_cmd_upk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hci_vendor_ble_qa_test_cmd_upk(int param_1,int param_2,ushort *param_3,uint param_4)

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

