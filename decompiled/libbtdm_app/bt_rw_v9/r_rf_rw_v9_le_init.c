/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
 * Source: libbtdm_app -> bt_rw_v9.o -> r_rf_rw_v9_le_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rf_rw_v9_le_init(void)

{
  int iVar1;
  uint uVar2;
  
  _DAT_60031080 = _DAT_60031080 & 0xff00ff00 | 0x640064;
  _DAT_60031084 = _DAT_60031084 & 0xff00ff00 | 0x640064;
  _DAT_60031088 = _DAT_60031088 & 0xff00ff00 | 0x640064;
  _DAT_6003108c = _DAT_6003108c & 0xff00ff00 | 0x640064;
  _DAT_60031090 = _DAT_60031090 & 0xffffff80 | 0xd;
  _DAT_60031000 = _DAT_60031000 | 0xf;
  _DAT_600310e0 = _DAT_600310e0 & 0xfc00fe00 | 0x1be00fa;
  _DAT_60031070 = 0;
  _DAT_60031074 = _DAT_60031074 & 0xffffdfff | 0x1020;
  _DAT_60031078 = 0xcc10100;
  _DAT_60031094 = 0x20202;
  _DAT_60031098 = 0xf020202;
  _DAT_6003109c = 0xf020202;
  _DAT_60011050 = (100 - (uint)sdk_cfg_priv_opts) * 8 & 0x7f8 | _DAT_60011050 & 0xfffff800;
  iVar1 = sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x11) == '\0') {
    _DAT_60011868 = _DAT_60011868 & 0xffffc7df;
  }
  else {
    iVar1 = sdk_config_get_opts_ext();
    if ((*(byte *)(iVar1 + 0x11) & 2) == 0) {
      uVar2 = 0x3800;
    }
    else {
      uVar2 = 0x3820;
    }
    _DAT_60011868 = uVar2 | _DAT_60011868;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar1 + 0x11) != '\0') {
    iVar1 = sdk_config_get_opts_ext();
    bt_bb_tx_cca_set(1,0x100 - (uint)*(byte *)(iVar1 + 0x12),0,0,0,0,0,0);
  }
  return;
}

