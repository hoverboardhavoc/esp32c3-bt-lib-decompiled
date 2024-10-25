/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_encrypt.o -> hci_le_ltk_req_neg_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_ltk_req_neg_reply_cmd_handler(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar2 + 0x20) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,0xc,*(code **)(_r_ip_funcs_p + 0x630));
    return 0;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(param_2,*(code **)(_r_plf_funcs_p + 0x38));
  if (param_1 < *(byte *)(iVar2 + 0xd)) {
    iVar2 = *(int *)(&llc_env + param_1 * 4);
    if (((iVar2 != 0) && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) &&
       (iVar2 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678)),
       iVar2 == 3)) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,*(code **)(_r_ip_funcs_p + 0x674));
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
      if (iVar1 == 0xe) {
        if (*(char *)(iVar2 + 0x3a) == '\0') {
          (**(code **)(_r_ip_funcs_p + 0x59c))(param_1,0xe,6,*(code **)(_r_ip_funcs_p + 0x59c));
        }
        else {
          (**(code **)(_r_ip_funcs_p + 0x690))(param_1,1,*(code **)(_r_ip_funcs_p + 0x690));
          iVar2 = *(int *)(&llc_env + param_1 * 4);
          *(ushort *)(iVar2 + 0x42) = *(ushort *)(iVar2 + 0x42) & 0xfdff;
          (**(code **)(_r_ip_funcs_p + 0x570))(param_1,6,*(code **)(_r_ip_funcs_p + 0x570));
        }
        uVar3 = 0;
        goto _L230;
      }
    }
  }
  uVar3 = 0xc;
_L230:
  (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,uVar3,*(code **)(_r_ip_funcs_p + 0x630));
  return 0;
}

