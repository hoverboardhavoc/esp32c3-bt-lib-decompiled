/*
 * Last changed at upstream commit bc9fd38197fb6a50e1b09791498782a1797e4757
 * https://github.com/espressif/esp32c3-bt-lib/commit/bc9fd38197fb6a50e1b09791498782a1797e4757
 * Upstream date: 2025-03-14 10:49:41 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(99e9a8dd)
 * Source: libbtdm_app -> llc_encrypt.o -> f_hci_le_ltk_req_neg_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_ltk_req_neg_reply_cmd_handler(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    iVar1 = *(int *)(&llc_env + param_1 * 4);
    if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) &&
       (iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678)),
       iVar1 == 3)) {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,*(code **)(_r_ip_funcs_p + 0x674));
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
      if (iVar2 == 0xe) {
        if (*(char *)(iVar1 + 0x3a) == '\0') {
          (**(code **)(_r_ip_funcs_p + 0x59c))(param_1,0xe,6,*(code **)(_r_ip_funcs_p + 0x59c));
        }
        else {
          (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
          iVar1 = *(int *)(&llc_env + param_1 * 4);
          *(ushort *)(iVar1 + 0x42) = *(ushort *)(iVar1 + 0x42) & 0xfdff;
          (**(code **)(_r_ip_funcs_p + 0x570))(param_1,6,*(code **)(_r_ip_funcs_p + 0x570));
        }
        uVar3 = 0;
        goto _L230;
      }
    }
  }
  uVar3 = 0xc;
_L230:
  (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_2,uVar3,*(code **)(_r_ip_funcs_p + 0x630));
  return 0;
}

