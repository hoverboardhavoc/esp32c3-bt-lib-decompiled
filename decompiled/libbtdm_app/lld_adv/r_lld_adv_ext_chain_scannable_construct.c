/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_chain_scannable_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_scannable_construct(int param_1)

{
  ushort uVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  code *pcVar9;
  uint uVar10;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar1 = *(ushort *)(iVar4 + 0x74);
  uVar10 = ((uint)*(byte *)(iVar4 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,7,0,0,1);
  iVar7 = _r_ip_funcs_p;
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
  iVar7 = (**(code **)(iVar7 + 0x1b0))
                    (param_1,uVar10,7,uVar1 & 3,1,*(ushort *)(iVar4 + 0x74) >> 2 & 1,0);
  bVar8 = *(byte *)(iVar4 + 0x91);
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar7;
  if ((bVar8 & 0xc0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar7 = param_1 * 0x5a;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar6 + iVar7 + 0x26);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar9 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar6 + iVar7 + 0x26) = uVar1 & 0x3ff | (ushort)bVar8 << 10;
  iVar6 = (*pcVar9)(0x400,pcVar9);
  uVar1 = *(ushort *)(iVar6 + iVar7 + 4);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar7 + 4) = uVar1 & 0xffcf | 0x10;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar7 + 0x34 + iVar6) = (short)uVar10 * 0xe + 0x1400;
  cVar3 = *(char *)(iVar4 + 0x90);
  if (cVar3 == '\x03') {
    cVar3 = '\x02';
  }
  iVar7 = (**(code **)(_r_modules_funcs_p + 4))(0xc,cVar3,*(code **)(_r_modules_funcs_p + 4));
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar7 + 0x96;
  sVar2 = *(short *)(iVar4 + 0x84);
  uVar5 = (uint)*(byte *)(iVar4 + 0x87) * 9 + 2 & 0xff;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar7 + uVar10 * 0xe);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(uVar10 * 0xe + iVar7) = (short)uVar5 * 0xe + 0x1400U | uVar1 & 0x8000;
  iVar7 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,uVar5,7,0,1,0,0,0);
  cVar3 = '\x02';
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar7;
  while (cVar3 = cVar3 + '\x01', sVar2 != 0) {
    bVar8 = *(char *)(iVar4 + 0x87) * '\t' + cVar3;
    iVar7 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,7,0,0,0,0,0);
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar7;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar7 + uVar5 * 0xe);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(uVar5 * 0xe + iVar7) = (ushort)bVar8 * 0xe + 0x1400 | uVar1 & 0x8000;
    uVar5 = (uint)bVar8;
  }
  *(char *)(iVar4 + 0x92) = cVar3;
  return;
}

