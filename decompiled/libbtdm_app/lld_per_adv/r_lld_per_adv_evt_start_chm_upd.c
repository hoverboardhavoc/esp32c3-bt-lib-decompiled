/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  byte bVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  void *__dest;
  code *pcVar10;
  int iVar11;
  
  bVar1 = *(byte *)(param_1 + 0x52);
  uVar6 = (uint)bVar1 * 9 & 0xff;
  if (*(char *)(param_1 + 0x3c) == '\0') {
    if ((*(char *)(param_1 + 0x3d) != '\0') &&
       ((ushort)(*(short *)(param_1 + 0x4c) - *(short *)(param_1 + 0x3a)) < 0x7fff)) {
      uVar5 = *(undefined2 *)(param_1 + 0x34);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar8 = (uint)bVar1 * 0x5a;
      *(undefined2 *)(iVar8 + 0x22 + iVar7) = uVar5;
      uVar5 = *(undefined2 *)(param_1 + 0x36);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar8 + 0x24 + iVar7) = uVar5;
      bVar1 = *(byte *)(param_1 + 0x38);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar8 + 0x26 + iVar7) = (ushort)bVar1;
      memcpy((void *)(param_1 + 0x2f),(void *)(param_1 + 0x34),5);
      bVar1 = *(byte *)(param_1 + 0x5a);
      *(undefined1 *)(param_1 + 0x3d) = 0;
      if (0x3f < bVar1) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = uVar6 * 0xe;
      iVar11 = iVar7 + 6;
      uVar4 = *(ushort *)(iVar8 + iVar11);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar8 + iVar11) = (ushort)bVar1 | uVar4 & 0xffc0;
      bVar1 = *(byte *)(param_1 + 0x5a);
      bVar2 = *(byte *)(param_1 + 0x5b);
      iVar7 = iVar7 + 2;
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar4 = *(ushort *)(iVar8 + iVar7);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar8 + iVar7) =
           uVar4 & 0xff | (ushort)(((uint)bVar1 + (uint)bVar2 + 1 & 0xff) << 8);
    }
  }
  else {
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = uVar6 * 0xe;
    sVar3 = *(short *)(iVar7 + 0xc + iVar8);
    if (sVar3 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x303,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar8 = *(ushort *)(param_1 + 0x4c) + 10;
    pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
    iVar11 = iVar8 * 0x10000;
    *(short *)(param_1 + 0x3a) = (short)((uint)iVar11 >> 0x10);
    puVar9 = (undefined1 *)(*pcVar10)(*(byte *)(param_1 + 0x59) + 7 + sVar3,pcVar10);
    *puVar9 = (char)((uint)iVar11 >> 0x10);
    puVar9 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (*(byte *)(param_1 + 0x59) + 8 + sVar3,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar9 = (char)((uint)iVar8 >> 8);
    uVar6 = 10;
    __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (sVar3 + *(byte *)(param_1 + 0x59) + 2,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(__dest,(void *)(param_1 + 0x34),5);
    if ((*(char *)(param_1 + 0x5a) != '\0') &&
       (uVar6 = (uint)(byte)(*(char *)(param_1 + 0x5a) + 9), 0x3f < uVar6)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x27d,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar8 + iVar7 + 6);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar8 + iVar7 + 6) = (ushort)uVar6 | uVar4 & 0xffc0;
    bVar1 = *(byte *)(param_1 + 0x5b);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = *(ushort *)(iVar8 + iVar7 + 2);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar8 + iVar7 + 2) = uVar4 & 0xff | (ushort)((uVar6 + bVar1 + 1 & 0xff) << 8);
    *(undefined2 *)(param_1 + 0x3c) = 0x100;
  }
  return;
}

