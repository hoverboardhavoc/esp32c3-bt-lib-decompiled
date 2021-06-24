/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
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
  
  uVar1 = _DAT_6001108c;
  if ((int)(_DAT_6001108c << 0xd) < 0) {
    _DAT_60011090 = _DAT_60011090 | 0x40000;
    (**(code **)(_r_ip_funcs_p + 0x248))(*(code **)(_r_ip_funcs_p + 0x248));
    (**(code **)(_r_plf_funcs_p + 0x2c))(5,*(code **)(_r_plf_funcs_p + 0x2c));
  }
  if ((int)(uVar1 << 0xc) < 0) {
    _DAT_60011090 = _DAT_60011090 | 0x80000;
    while (-1 < _DAT_600110d4 << 2) {
      (**(code **)(_r_ip_funcs_p + 0x250))
                (_DAT_600110d8 >> 0xf & 0xff,_DAT_600110d8 >> 0x17 & 0x7f,_DAT_600110d8 >> 0x1e,
                 *(code **)(_r_ip_funcs_p + 0x250));
    }
    (**(code **)(_r_plf_funcs_p + 0x2c))(5,*(code **)(_r_plf_funcs_p + 0x2c));
  }
  if ((uVar1 & 0x400) != 0) {
    _DAT_60011090 = _DAT_60011090 | 0x400;
    iVar2 = bt_bb_recorrect_is_dead();
    if (iVar2 != 0) {
      bt_bb_restart_hw_recorrect();
    }
  }
  if (-1 < (int)(uVar1 << 0xf)) {
    return;
  }
  _DAT_60011090 = _DAT_60011090 | 0x10000;
  _DAT_60011868 = _DAT_60011868 & 0xffffe7df | 0x1820;
  return;
}

