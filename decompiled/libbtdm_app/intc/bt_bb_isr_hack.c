/*
 * Last changed at upstream commit 98dcc9591365b5ac486a9f0b474c36bf8c4ca97b
 * https://github.com/espressif/esp32c3-bt-lib/commit/98dcc9591365b5ac486a9f0b474c36bf8c4ca97b
 * Upstream date: 2022-03-01 14:41:26 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (d913766) Add the pll track feature to keep the ble connection stable when the environment temprature increase form 0 to 74.
 * Source: libbtdm_app -> intc.o -> bt_bb_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_bb_isr_hack(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_a1;
  uint uVar4;
  uint uVar5;
  
  uVar3 = _DAT_6001108c;
  if ((int)(_DAT_6001108c << 0xd) < 0) {
    _DAT_60011090 = _DAT_60011090 | 0x40000;
    (**(code **)(_r_ip_funcs_p + 0x248))(*(code **)(_r_ip_funcs_p + 0x248));
    (**(code **)(_r_plf_funcs_p + 0x2c))(5,*(code **)(_r_plf_funcs_p + 0x2c));
  }
  if ((int)(uVar3 << 0xc) < 0) {
    _DAT_60011090 = _DAT_60011090 | 0x80000;
    while (-1 < _DAT_600110d4 << 2) {
      uVar4 = _DAT_600110d8 >> 0xf;
      uVar5 = _DAT_600110d8 >> 0x1e;
      uVar1 = _DAT_600110d8 >> 0x18 & 0x3f;
      if (0x27 < uVar1) {
        (**(code **)(_r_plf_funcs_p + 0xc))(uVar1,0,"intc.c",0xa0,*(code **)(_r_plf_funcs_p + 0xc));
      }
      (**(code **)(_r_ip_funcs_p + 0x250))
                (uVar4 & 0xff,uVar1,uVar5,*(code **)(_r_ip_funcs_p + 0x250));
    }
    (**(code **)(_r_plf_funcs_p + 0x2c))(5,*(code **)(_r_plf_funcs_p + 0x2c));
  }
  if ((uVar3 & 0x400) != 0) {
    _DAT_60011090 = _DAT_60011090 | 0x400;
    iVar2 = bt_bb_recorrect_is_dead();
    if (iVar2 != 0) {
      bt_bb_restart_hw_recorrect();
    }
  }
  if ((int)(uVar3 << 0xf) < 0) {
    _DAT_60011090 = _DAT_60011090 | 0x10000;
    bt_bb_restart_hw_recorrect();
  }
  if (sdk_cfg_priv_opts_extend != '\0') {
    if ((int)(uVar3 << 0x11) < 0) {
      _DAT_60011090 = _DAT_60011090 | 0x4000;
    }
    if ((int)(uVar3 << 0x12) < 0) {
      _DAT_60011090 = _DAT_60011090 | 0x2000;
    }
    _LANCHOR0 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
    uVar3 = _LANCHOR0 - _LANCHOR1 & 0xfffffff;
    DAT_0001030c = extraout_a1;
    if ((uVar3 < 0x8000001) && (0xc80 < uVar3)) {
      bt_track_pll_cap();
      _LANCHOR1 = _LANCHOR0;
    }
  }
  return;
}

