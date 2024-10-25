/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwip_driver.o -> r_rwip_timer_hus_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_timer_hus_handler(void)

{
  _rwip_env = 0xffffffff;
  _DAT_6003100c = _DAT_6003100c & 0xfffff7ff;
  if (sdk_cfg_priv_opts != '\0') {
    _DAT_6003138c = 0x800;
  }
                    /* WARNING: Could not recover jumptable at 0x00010734. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x6a8))();
  return;
}

