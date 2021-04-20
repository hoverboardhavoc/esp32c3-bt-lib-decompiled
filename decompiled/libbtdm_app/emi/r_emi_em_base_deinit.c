/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> emi.o -> r_emi_em_base_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_emi_em_base_deinit(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = 0;
  do {
    iVar1 = 0x220;
    if ((int)uVar2 < 0x30) {
      iVar1 = 0x204;
    }
    uVar5 = *(uint *)(uVar2 * 4 + iVar1 + 0x60031000) & 0x3ffff;
    if (uVar5 != 0) {
      uVar3 = _DAT_600312c4;
      uVar4 = uVar2;
      if (0x1f < (int)uVar2) {
        if ((int)uVar2 < 0x30) {
          uVar3 = _DAT_600312c8;
          uVar4 = uVar2 - 0x20;
        }
        else {
          uVar3 = _DAT_60031300;
          uVar4 = uVar2 - 0x30;
        }
      }
      if (((1 << (uVar4 & 0x1f) & uVar3) >> (uVar4 & 0x1f) & 0xff) == 0) {
        (**(code **)(_r_plf_funcs_p + 0x10))
                  (uVar2,uVar5,"emi.c",0x5b,*(code **)(_r_plf_funcs_p + 0x10));
      }
      (**(code **)(_r_osi_funcs_p + 0x7c))
                (uVar5 << 2 | 0x3fc00000,*(code **)(_r_osi_funcs_p + 0x7c));
      if ((int)uVar2 < 0x20) {
        _DAT_600312c4 = ~(1 << (uVar2 & 0x1f)) & _DAT_600312c4;
      }
      else if ((int)uVar2 < 0x30) {
        _DAT_600312c8 = ~(1 << (uVar2 - 0x20 & 0x1f)) & _DAT_600312c8;
      }
      else {
        _DAT_60031300 = ~(1 << (uVar2 - 0x30 & 0x1f)) & _DAT_60031300;
      }
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x38);
  return;
}

