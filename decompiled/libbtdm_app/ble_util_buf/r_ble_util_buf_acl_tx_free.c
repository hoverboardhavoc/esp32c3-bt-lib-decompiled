/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_buf_acl_tx_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_buf_acl_tx_free(int param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  
  uVar1 = param_1 - 0x9c00U >> 10;
  uVar3 = uVar1 & 0xff;
  uVar1 = uVar1 & 0xff;
  if (0xb < uVar3) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar1,param_1,"ble_util_buf.c",0x18d,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (uVar3 < *(byte *)(_p_ble_util_buf_env + 0x1bb)) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    pcVar2 = *(code **)(_r_modules_funcs_p + 0x4c);
  }
  else {
    (**(code **)(_r_plf_funcs_p + 0xb4))(param_1,*(code **)(_r_plf_funcs_p + 0xb4));
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    pcVar2 = *(code **)(_r_modules_funcs_p + 0x44);
  }
  (*pcVar2)(_p_ble_util_buf_env + 0x10,_p_ble_util_buf_env + (uVar1 + 0x21) * 8,pcVar2);
                    /* WARNING: Could not recover jumptable at 0x000107d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

