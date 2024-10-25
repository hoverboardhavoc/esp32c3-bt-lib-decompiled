/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_le_ping.o -> llc_auth_payl_nearly_to_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
llc_auth_payl_nearly_to_handler
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar3 + 0x20) == '\0') {
    return 0;
  }
  uVar4 = param_3 >> 8 & 0xff;
  iVar3 = *(int *)(&llc_env + (param_3 >> 8) * 4);
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))
                    (param_1,param_2,param_4,*(code **)(_r_plf_funcs_p + 0x38));
  if ((((uVar4 < *(byte *)(iVar1 + 0xd)) &&
       (iVar1 = *(int *)(&llc_env + (param_3 >> 8) * 4), iVar1 != 0)) &&
      ((*(byte *)(iVar1 + 0x44) & 3) != 3)) && ((*(ushort *)(iVar3 + 0x42) & 0x20) != 0)) {
    puVar2 = (undefined4 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x10c,param_3,8,*(code **)(_r_modules_funcs_p + 200));
    *(undefined1 *)(puVar2 + 1) = 8;
    (**(code **)(_r_ip_funcs_p + 0x684))(uVar4,0,*(code **)(_r_ip_funcs_p + 0x684));
    *puVar2 = *(undefined4 *)(_r_ip_funcs_p + 0x60c);
    (**(code **)(_r_modules_funcs_p + 0xe0))(puVar2,*(code **)(_r_modules_funcs_p + 0xe0));
  }
  return 0;
}

