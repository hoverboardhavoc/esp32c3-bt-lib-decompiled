/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke.o -> r_ke_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_init(code *pcRam000000fc,code *pcRam00000170)

{
  _DAT_00011008 = 0;
  _DAT_0001100c = 0;
  _ke_env = 0;
  _r_modules_funcs_p = 0;
  (*pcRam000000fc)(pcRam000000fc);
  _DAT_00011008 = 0;
  _DAT_0001100c = 0;
  _r_modules_funcs_p = 0;
  _DAT_00011010 = 0;
  _DAT_00011014 = 0;
  _ke_env = 0;
  (*pcRam00000170)(pcRam00000170);
                    /* WARNING: Could not recover jumptable at 0x00010074. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xbc))();
  return;
}

