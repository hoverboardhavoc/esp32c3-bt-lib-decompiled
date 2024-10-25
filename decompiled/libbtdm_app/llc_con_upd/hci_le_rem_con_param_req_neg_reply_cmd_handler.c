/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_con_upd.o -> hci_le_rem_con_param_req_neg_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
hci_le_rem_con_param_req_neg_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    uVar2 = 0x12;
    if (*(char *)(param_2 + 2) != ';') goto _L289;
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,0x12,*(code **)(_r_ip_funcs_p + 0x674));
    if (iVar1 != 0) {
      (**(code **)(_r_ip_funcs_p + 0x600))
                (param_1,8,*(undefined1 *)(param_2 + 2),*(code **)(_r_ip_funcs_p + 0x600));
      uVar2 = 0;
      goto _L289;
    }
  }
  uVar2 = 0xc;
_L289:
  (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,uVar2,*(code **)(_r_ip_funcs_p + 0x630));
  return 0;
}

