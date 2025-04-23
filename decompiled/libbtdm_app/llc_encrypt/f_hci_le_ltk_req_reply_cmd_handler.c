/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_encrypt.o -> f_hci_le_ltk_req_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_ltk_req_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    if (((*(int *)(&llc_env + param_1 * 4) != 0) &&
        ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) &&
       (iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678)),
       iVar1 == 3)) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,*(code **)(_r_ip_funcs_p + 0x674));
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
      iVar1 = _r_ip_funcs_p;
      if (iVar3 == 0xe) {
        memcpy((void *)(iVar2 + 0x10),(void *)(param_2 + 2),0x10);
        (**(code **)(iVar1 + 0x59c))(param_1,0xe,0,*(code **)(iVar1 + 0x59c));
        uVar4 = 0;
        goto _L232;
      }
    }
  }
  uVar4 = 0xc;
_L232:
  (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,uVar4,*(code **)(_r_ip_funcs_p + 0x630));
  return 0;
}

