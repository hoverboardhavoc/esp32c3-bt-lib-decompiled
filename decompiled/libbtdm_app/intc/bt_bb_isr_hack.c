/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
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
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = _DAT_6001108c;
  if ((int)(_DAT_6001108c << 0xd) < 0) {
    _DAT_60011090 = _DAT_60011090 | 0x40000;
    (**(code **)(_r_ip_funcs_p + 0x248))(*(code **)(_r_ip_funcs_p + 0x248));
    (**(code **)(_r_plf_funcs_p + 0x2c))(5,*(code **)(_r_plf_funcs_p + 0x2c));
  }
  if ((int)(uVar1 << 0xc) < 0) {
    _DAT_60011090 = _DAT_60011090 | 0x80000;
    while (-1 < _DAT_600110d4 << 2) {
      uVar4 = _DAT_600110d8 >> 0xf;
      uVar5 = _DAT_600110d8 >> 0x1e;
      uVar2 = _DAT_600110d8 >> 0x18 & 0x3f;
      if (0x27 < uVar2) {
        (**(code **)(_r_plf_funcs_p + 0xc))(uVar2,0,"intc.c",0x9b,*(code **)(_r_plf_funcs_p + 0xc));
      }
      (**(code **)(_r_ip_funcs_p + 0x250))
                (uVar4 & 0xff,uVar2,uVar5,*(code **)(_r_ip_funcs_p + 0x250));
    }
    (**(code **)(_r_plf_funcs_p + 0x2c))(5,*(code **)(_r_plf_funcs_p + 0x2c));
  }
  if ((uVar1 & 0x400) != 0) {
    _DAT_60011090 = _DAT_60011090 | 0x400;
    iVar3 = bt_bb_recorrect_is_dead();
    if (iVar3 != 0) {
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

