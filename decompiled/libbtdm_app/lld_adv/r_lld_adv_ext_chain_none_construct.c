/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_chain_none_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_none_construct(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  byte bVar10;
  ushort uVar11;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  cVar9 = *(char *)(iVar4 + 0x87) * '\t';
  uVar2 = *(ushort *)(iVar4 + 0x74);
  uVar11 = 0;
  bVar10 = cVar9 + 1;
  if (((uVar2 & 3) == 0) &&
     (uVar11 = uVar2 >> 2 & (ushort)(*(short *)(iVar4 + 0x82) == 0), *(short *)(iVar4 + 0x82) == 0))
  {
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    uVar11 = uVar11 | *(char *)(iVar6 + 0x1a) != '\0';
  }
  if (((*(short *)(iVar4 + 0x82) == 0) && (*(int *)(iVar4 + 0x68) == 0)) && (uVar11 == 0)) {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))
                      (param_1,cVar9,7,*(ushort *)(iVar4 + 0x74) >> 5 & 1 ^ 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,0,0);
    bVar10 = *(byte *)(iVar4 + 0x87);
    *(undefined1 *)(iVar4 + 0x95) = 0;
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    cVar9 = '\x01';
    *(undefined2 *)((uint)bVar10 * 0x7e + 0x12 + iVar6) = 0;
  }
  else {
    iVar7 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,cVar9,7,0,0,1);
    iVar6 = _r_ip_funcs_p;
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar7;
    sVar3 = *(short *)(iVar4 + 0x82);
    iVar6 = (**(code **)(iVar6 + 0x1b0))
                      (param_1,(uint)bVar10,7,uVar2 & 3,*(ushort *)(iVar4 + 0x74) >> 5 & 1 ^ 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,0);
    bVar1 = *(byte *)(iVar4 + 0x91);
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    if ((bVar1 & 0xc0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = param_1 * 0x5a;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar6 + iVar7 + 0x26);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar7 + 0x26) = uVar2 & 0x3ff | (ushort)bVar1 << 10;
    bVar1 = *(byte *)(iVar4 + 0x90);
    if ((bVar1 & 0xfc) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x1bf,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar6 + iVar7 + 4);
    iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar6 = _r_plf_funcs_p;
    *(ushort *)(iVar8 + iVar7 + 4) = uVar2 & 0xffcf | (ushort)bVar1 << 4;
    iVar6 = (**(code **)(iVar6 + 0xbc))(0x400,*(code **)(iVar6 + 0xbc));
    *(ushort *)(iVar7 + 0x34 + iVar6) = (ushort)bVar10 * 0xe + 0x1400;
    uVar5 = (uint)bVar10;
    cVar9 = '\x01';
    while (sVar3 != 0) {
      bVar10 = *(char *)(iVar4 + 0x87) * '\t' + cVar9 + '\x01';
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,(uint)bVar10,7,0,0,0,1,0);
      *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar6 + uVar5 * 0xe);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(uVar5 * 0xe + iVar6) = (ushort)bVar10 * 0xe + 0x1400 | uVar2 & 0x8000;
      uVar5 = (uint)bVar10;
      cVar9 = cVar9 + '\x01';
    }
  }
  *(char *)(iVar4 + 0x92) = cVar9 + '\x01';
  return;
}

