/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke_timer.o -> r_ke_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_timer_set(uint param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0x3fffff;
  if ((param_3 < 0x400000) && (uVar2 = param_3, param_3 == 0)) {
    uVar2 = 1;
  }
  bVar1 = false;
  if ((_DAT_00011014 != 0) && (*(ushort *)(_DAT_00011014 + 4) == param_1)) {
    bVar1 = *(ushort *)(_DAT_00011014 + 6) == param_2;
  }
  iVar3 = (**(code **)(_r_modules_funcs_p + 0x158))
                    (&ke_env,*(undefined4 *)(_r_modules_funcs_p + 0xa0),param_1 << 0x10 | param_2,
                     *(code **)(_r_modules_funcs_p + 0x158));
  if (iVar3 == 0) {
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x120))(0xc,2,*(code **)(_r_modules_funcs_p + 0x120));
    if (iVar3 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))("ke_timer.c",0xfa,*(code **)(_r_plf_funcs_p + 8));
    }
    *(short *)(iVar3 + 4) = (short)param_1;
    *(short *)(iVar3 + 6) = (short)param_2;
  }
  iVar4 = (**(code **)(_r_modules_funcs_p + 0xa4))(*(code **)(_r_modules_funcs_p + 0xa4));
  *(uint *)(iVar3 + 8) = uVar2 + iVar4 & 0x7fffff;
  (**(code **)(_r_modules_funcs_p + 0x15c))
            (&ke_env,iVar3,*(undefined4 *)(_r_modules_funcs_p + 0x9c),
             *(code **)(_r_modules_funcs_p + 0x15c));
  if ((bVar1) || (iVar3 == _DAT_00011014)) {
    (**(code **)(_r_modules_funcs_p + 0x2cc))
              (*(undefined4 *)(_DAT_00011014 + 8),*(code **)(_r_modules_funcs_p + 0x2cc));
  }
  iVar3 = (**(code **)(_r_modules_funcs_p + 0xac))
                    (uVar2 + iVar4,*(code **)(_r_modules_funcs_p + 0xac));
  if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001026a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_modules_funcs_p + 0x108))(4);
    return;
  }
  return;
}

