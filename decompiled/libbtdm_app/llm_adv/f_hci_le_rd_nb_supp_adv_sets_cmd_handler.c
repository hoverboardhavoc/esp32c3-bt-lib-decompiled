/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_adv.o -> f_hci_le_rd_nb_supp_adv_sets_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_rd_nb_supp_adv_sets_cmd_handler(undefined4 param_1)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,0,param_1,2,*(code **)(_r_modules_funcs_p + 200));
  puVar2[1] = 0;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    *puVar2 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    *puVar2 = 0;
    for (uVar1 = 0; iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
        uVar1 < *(byte *)(iVar3 + 0xd); uVar1 = uVar1 + 1 & 0xff) {
      if (*(byte *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) < 4) {
        puVar2[1] = puVar2[1] + '\x01';
      }
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x8c))(puVar2,*(code **)(_r_ip_funcs_p + 0x8c));
  return 0;
}

