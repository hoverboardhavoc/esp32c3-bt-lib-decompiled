/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_le_ping.o -> f_llc_auth_payl_nearly_to_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_llc_auth_payl_nearly_to_handler(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = param_1 >> 8 & 0xff;
  iVar1 = *(int *)(&llc_env + (param_1 >> 8) * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((((uVar4 < *(byte *)(iVar2 + 0xd)) &&
       (iVar2 = *(int *)(&llc_env + (param_1 >> 8) * 4), iVar2 != 0)) &&
      ((*(byte *)(iVar2 + 0x44) & 3) != 3)) && ((*(ushort *)(iVar1 + 0x42) & 0x20) != 0)) {
    puVar3 = (undefined4 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x10c,param_1,8,*(code **)(_r_modules_funcs_p + 200));
    *(undefined1 *)(puVar3 + 1) = 8;
    (**(code **)(_r_ip_funcs_p + 0x684))(uVar4,0,*(code **)(_r_ip_funcs_p + 0x684));
    *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x60c);
    (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3,*(code **)(_r_modules_funcs_p + 0xe0));
  }
  return 0;
}

