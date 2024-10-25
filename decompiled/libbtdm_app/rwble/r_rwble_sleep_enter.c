/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> rwble.o -> r_rwble_sleep_enter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwble_sleep_enter(void)

{
  _rwble_env = _DAT_6003100c;
  _DAT_6003100c = 0;
  _DAT_60031018 = 0xffffffff;
  if (sdk_cfg_priv_opts != '\0') {
    for (; (_DAT_600312d8 >> 5 & 0x1f) != 0; _DAT_600312d8 = _DAT_600312d8 | 1) {
    }
  }
  _DAT_00011020 = (**(code **)(_r_plf_funcs_p + 0x78))(*(code **)(_r_plf_funcs_p + 0x78));
  (**(code **)(_r_plf_funcs_p + 0x80))(0,*(code **)(_r_plf_funcs_p + 0x80));
                    /* WARNING: Could not recover jumptable at 0x00010738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0x7c))();
  return;
}

