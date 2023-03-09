/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> intc.o -> r_bt_bb_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_bt_bb_isr(void)

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
        (**(code **)(_r_plf_funcs_p + 0xc))(uVar2,0,"intc.c",0xaa,*(code **)(_r_plf_funcs_p + 0xc));
      }
      (**(code **)(_r_ip_funcs_p + 0x250))
                (uVar4 & 0xff,uVar2,uVar5,*(code **)(_r_ip_funcs_p + 0x250));
    }
    (**(code **)(_r_plf_funcs_p + 0x2c))(5,*(code **)(_r_plf_funcs_p + 0x2c));
  }
  if ((uVar1 & 0x400) != 0) {
    _DAT_60011090 = _DAT_60011090 | 0x400;
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if ((*(char *)(iVar3 + 0x11) != '\0') &&
       (iVar3 = (**(code **)(_r_plf_funcs_p + 0xfc))(*(code **)(_r_plf_funcs_p + 0xfc)), iVar3 != 0)
       ) {
      (**(code **)(_r_plf_funcs_p + 0x100))(*(code **)(_r_plf_funcs_p + 0x100));
    }
  }
  if ((int)(uVar1 << 0xf) < 0) {
    _DAT_60011090 = _DAT_60011090 | 0x10000;
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if (*(char *)(iVar3 + 0x11) != '\0') {
      (**(code **)(_r_plf_funcs_p + 0x100))(*(code **)(_r_plf_funcs_p + 0x100));
    }
  }
  if ((int)(uVar1 << 0x10) < 0) {
    _DAT_60011090 = _DAT_60011090 | 0x8000;
  }
  return;
}

