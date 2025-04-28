/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_evt_start_chm_upd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_evt_start_chm_upd(int param_1)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  void *__dest;
  char cVar9;
  code *pcVar11;
  int iVar12;
  byte bVar10;
  
  bVar10 = *(byte *)(param_1 + 0x52);
  uVar5 = (uint)bVar10 * 9 & 0xff;
  if (*(char *)(param_1 + 0x3c) == '\0') {
    if ((*(char *)(param_1 + 0x3d) != '\0') &&
       ((ushort)(*(short *)(param_1 + 0x4c) - *(short *)(param_1 + 0x3a)) < 0x7fff)) {
      uVar4 = *(undefined2 *)(param_1 + 0x34);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = (uint)bVar10 * 0x5a;
      *(undefined2 *)(iVar7 + 0x22 + iVar6) = uVar4;
      uVar4 = *(undefined2 *)(param_1 + 0x36);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + 0x24 + iVar6) = uVar4;
      bVar10 = *(byte *)(param_1 + 0x38);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + 0x26 + iVar6) = (ushort)bVar10;
      memcpy((void *)(param_1 + 0x2f),(void *)(param_1 + 0x34),5);
      bVar10 = *(byte *)(param_1 + 0x5a);
      *(undefined1 *)(param_1 + 0x3d) = 0;
      if ((bVar10 & 0xc0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar12 = uVar5 * 0xe;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = iVar12 + 6;
      uVar3 = *(ushort *)(iVar6 + iVar7);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar7) = uVar3 & 0xffc0 | (ushort)bVar10;
      bVar10 = *(byte *)(param_1 + 0x5b);
      bVar1 = *(byte *)(param_1 + 0x5a);
      iVar12 = iVar12 + 2;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar6 + iVar12);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar12) =
           uVar3 & 0xff | (ushort)(((uint)bVar1 + (uint)bVar10 + 1 & 0xff) << 8);
    }
  }
  else {
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar6 = uVar5 * 0xe;
    sVar2 = *(short *)(iVar6 + 0xc + iVar7);
    if (sVar2 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x303,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = *(ushort *)(param_1 + 0x4c) + 10;
    pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
    iVar12 = iVar7 * 0x10000;
    *(short *)(param_1 + 0x3a) = (short)((uint)iVar12 >> 0x10);
    puVar8 = (undefined1 *)(*pcVar11)(*(byte *)(param_1 + 0x59) + 7 + sVar2,pcVar11);
    *puVar8 = (char)((uint)iVar12 >> 0x10);
    puVar8 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (*(byte *)(param_1 + 0x59) + 8 + sVar2,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar8 = (char)((uint)iVar7 >> 8);
    __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar2 + *(byte *)(param_1 + 0x59) + 2,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(__dest,(void *)(param_1 + 0x34),5);
    cVar9 = *(char *)(param_1 + 0x5a);
    if (cVar9 == '\0') {
      cVar9 = '\x01';
    }
    bVar10 = cVar9 + 9;
    if ((bVar10 & 0xc0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27d,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar7 + iVar6 + 6);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + iVar6 + 6) = uVar3 & 0xffc0 | (ushort)bVar10;
    bVar1 = *(byte *)(param_1 + 0x5b);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar7 + iVar6 + 2);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + iVar6 + 2) = uVar3 & 0xff | (ushort)(((uint)bVar10 + bVar1 + 1 & 0xff) << 8)
    ;
    *(undefined2 *)(param_1 + 0x3c) = 0x100;
  }
  return;
}

