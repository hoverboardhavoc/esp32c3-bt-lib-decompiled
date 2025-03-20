/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  code *pcVar9;
  char cVar10;
  int iVar12;
  int iVar13;
  byte bVar11;
  
  bVar11 = *(byte *)(param_1 + 0x52);
  uVar5 = (uint)bVar11 * 9 & 0xff;
  if (*(char *)(param_1 + 0x3c) == '\0') {
    if ((*(char *)(param_1 + 0x3d) != '\0') &&
       ((ushort)(*(short *)(param_1 + 0x4c) - *(short *)(param_1 + 0x3a)) < 0x7fff)) {
      uVar4 = *(undefined2 *)(param_1 + 0x34);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar12 = (uint)bVar11 * 0x5a;
      *(undefined2 *)(iVar6 + iVar12 + 0x22) = uVar4;
      uVar4 = *(undefined2 *)(param_1 + 0x36);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = _r_plf_funcs_p;
      *(undefined2 *)(iVar7 + iVar12 + 0x24) = uVar4;
      bVar11 = *(byte *)(param_1 + 0x38);
      iVar6 = (**(code **)(iVar6 + 0xbc))(0x400,*(code **)(iVar6 + 0xbc));
      *(ushort *)(iVar12 + 0x26 + iVar6) = (ushort)bVar11;
      memcpy((void *)(param_1 + 0x2f),(void *)(param_1 + 0x34),5);
      bVar11 = *(byte *)(param_1 + 0x5a);
      *(undefined1 *)(param_1 + 0x3d) = 0;
      if ((bVar11 & 0xc0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x27d,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = uVar5 * 0xe;
      iVar13 = iVar7 + 6;
      uVar3 = *(ushort *)(iVar6 + iVar13);
      iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = _r_plf_funcs_p;
      *(ushort *)(iVar12 + iVar13) = uVar3 & 0xffc0 | (ushort)bVar11;
      bVar11 = *(byte *)(param_1 + 0x5a);
      bVar1 = *(byte *)(param_1 + 0x5b);
      iVar6 = (**(code **)(iVar6 + 0xbc))(0x1400,*(code **)(iVar6 + 0xbc));
      iVar7 = iVar7 + 2;
      uVar3 = *(ushort *)(iVar6 + iVar7);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + iVar6) =
           uVar3 & 0xff | (ushort)(((uint)bVar1 + (uint)bVar11 + 1 & 0xff) << 8);
    }
  }
  else {
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar6 = uVar5 * 0xe;
    sVar2 = *(short *)(iVar7 + iVar6 + 0xc);
    if (sVar2 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x2f9,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = *(ushort *)(param_1 + 0x4c) + 10;
    pcVar9 = *(code **)(_r_plf_funcs_p + 0xbc);
    iVar12 = iVar7 * 0x10000;
    *(short *)(param_1 + 0x3a) = (short)((uint)iVar12 >> 0x10);
    puVar8 = (undefined1 *)(*pcVar9)(*(byte *)(param_1 + 0x59) + 7 + sVar2,pcVar9);
    *puVar8 = (char)((uint)iVar12 >> 0x10);
    puVar8 = (undefined1 *)
             (**(code **)(_r_plf_funcs_p + 0xbc))
                       (*(byte *)(param_1 + 0x59) + 8 + sVar2,*(code **)(_r_plf_funcs_p + 0xbc));
    *puVar8 = (char)((uint)iVar7 >> 8);
    __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (*(byte *)(param_1 + 0x59) + 2 + sVar2,
                                *(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(__dest,(void *)(param_1 + 0x34),5);
    cVar10 = *(char *)(param_1 + 0x5a);
    if (cVar10 == '\0') {
      cVar10 = '\x01';
    }
    bVar11 = cVar10 + 9;
    if ((bVar11 & 0xc0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x27d,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = *(ushort *)(iVar7 + iVar6 + 6);
    iVar12 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar7 = _r_plf_funcs_p;
    *(ushort *)(iVar12 + iVar6 + 6) = uVar3 & 0xffc0 | (ushort)bVar11;
    bVar1 = *(byte *)(param_1 + 0x5b);
    iVar7 = (**(code **)(iVar7 + 0xbc))(0x1400,*(code **)(iVar7 + 0xbc));
    uVar3 = *(ushort *)(iVar7 + iVar6 + 2);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + 2 + iVar7) = uVar3 & 0xff | (ushort)(((uint)bVar11 + bVar1 + 1 & 0xff) << 8)
    ;
    *(undefined2 *)(param_1 + 0x3c) = 0x100;
  }
  return;
}

