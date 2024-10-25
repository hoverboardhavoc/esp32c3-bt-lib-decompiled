/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_gpio_set_level
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_gpio_set_level(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _DAT_6000400c;
  if ((param_1 != 0xff) && (iVar1 = 1 << (param_1 & 0x1f), param_2 != 0)) {
    _DAT_60004008 = iVar1;
    return;
  }
  _DAT_6000400c = iVar1;
  return;
}

