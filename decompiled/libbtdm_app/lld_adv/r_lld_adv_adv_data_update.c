/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_adv_data_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_adv_data_update(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    ets_printf("adv_adv_free\n");
  }
  else if (*(char *)(iVar1 + 0x89) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x17c))(1,0,*(code **)(_r_ip_funcs_p + 0x17c));
  }
  else {
    if (*(short *)(iVar1 + 0x24) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd8))(*(code **)(_r_ip_funcs_p + 0xd8));
    }
    iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
    *(undefined2 *)(iVar1 + 0x28) = param_2;
    *(undefined2 *)(iVar1 + 0x24) = param_3;
  }
                    /* WARNING: Could not recover jumptable at 0x00015f66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

