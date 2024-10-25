/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_rom_ref_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_rom_ref_init(void)

{
  undefined1 uVar1;
  undefined1 *__s;
  int iVar2;
  
  __s = _sdk_cfg_priv_opts;
  if ((*(code **)(_r_osi_funcs_p + 0x80) == (code *)0x0) ||
     (iVar2 = (**(code **)(_r_osi_funcs_p + 0x80))(_sdk_cfg_priv_opts), iVar2 != 0)) {
    memset(__s,0,6);
  }
  else {
    uVar1 = __s[5];
    __s[5] = *__s;
    *__s = uVar1;
    uVar1 = __s[4];
    __s[4] = __s[1];
    __s[1] = uVar1;
    uVar1 = __s[3];
    __s[3] = __s[2];
    __s[2] = uVar1;
  }
  bt_rf_coex_cfg_overwrite();
  if (2 < _g_bt_plf_log_level) {
    ets_printf("BD_ADDR: %02X:%02X:%02X:%02X:%02X:%02X\n",__s[5],__s[4],__s[3],__s[2],__s[1],*__s);
    return;
  }
  return;
}

