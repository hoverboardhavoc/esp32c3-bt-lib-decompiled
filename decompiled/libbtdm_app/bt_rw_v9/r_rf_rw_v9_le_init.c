/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  int iVar2;
  
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
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x11) == '\0') {
    _DAT_60011868 = _DAT_60011868 & 0xffffc7df;
  }
  else {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    iVar1 = -0x7e0;
    if ((*(byte *)(iVar2 + 0x11) & 2) == 0) {
      iVar1 = -0x800;
    }
    _DAT_60011868 = iVar1 + 0x4000U | _DAT_60011868;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x19) == '\x01') {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    bt_bb_tx_cca_set(1,0x100 - (uint)*(byte *)(iVar1 + 0x12),0,0,0,0,0,0);
  }
  return;
}

