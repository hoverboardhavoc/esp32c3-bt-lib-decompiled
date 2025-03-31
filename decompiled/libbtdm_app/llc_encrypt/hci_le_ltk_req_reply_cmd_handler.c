/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app -> llc_encrypt.o -> hci_le_ltk_req_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_ltk_req_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x20) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,0xc,*(code **)(_r_ip_funcs_p + 0x630));
    return 0;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((((param_1 < *(byte *)(iVar2 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
      ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) &&
     (iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678)),
     iVar2 == 3)) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,*(code **)(_r_ip_funcs_p + 0x674));
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
    if (iVar1 == 0xe) {
      memcpy((void *)(iVar2 + 0x10),(void *)(param_2 + 2),0x10);
      (**(code **)(_r_ip_funcs_p + 0x59c))(param_1,0xe,0,*(code **)(_r_ip_funcs_p + 0x59c));
      uVar3 = 0;
      goto _L233;
    }
  }
  uVar3 = 0xc;
_L233:
  (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,uVar3,*(code **)(_r_ip_funcs_p + 0x630));
  return 0;
}

