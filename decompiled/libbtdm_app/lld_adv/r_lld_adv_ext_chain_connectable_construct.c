/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_chain_connectable_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_connectable_construct(int param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  code *pcVar8;
  ushort uVar9;
  ushort uVar10;
  uint uVar11;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar9 = *(ushort *)(iVar3 + 0x74) & 3;
  uVar4 = ((uint)*(byte *)(iVar3 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,7,uVar9,0,0,1,1);
  iVar6 = _r_ip_funcs_p;
  *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
  sVar2 = *(short *)(iVar3 + 0x82);
  iVar6 = (**(code **)(iVar6 + 0x1b0))
                    (param_1,uVar4,7,uVar9,1,*(ushort *)(iVar3 + 0x74) >> 2 & 1,1,0);
  *(int *)(iVar3 + 0x6c) = iVar6 + *(int *)(iVar3 + 0x6c);
  if (sVar2 != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x627,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar11 = (uint)*(byte *)(iVar3 + 0x91) << 10;
  if ((uVar11 & 0x30000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = param_1 * 0x5a;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar9 = *(ushort *)(iVar6 + iVar5 + 0x26);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar8 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar6 + iVar5 + 0x26) = uVar9 & 0x3ff | (ushort)uVar11;
  iVar6 = (*pcVar8)(0x400,pcVar8);
  uVar9 = *(ushort *)(iVar6 + iVar5 + 4);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar5 + 4) = uVar9 & 0xffcf | 0x10;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar5 + 0x34 + iVar6) = (short)uVar4 * 0xe + 0x1400;
  cVar7 = *(char *)(iVar3 + 0x90);
  if (cVar7 == '\x03') {
    cVar7 = '\x02';
  }
  iVar6 = (**(code **)(_r_modules_funcs_p + 4))(0x22,cVar7,*(code **)(_r_modules_funcs_p + 4));
  bVar1 = *(byte *)(iVar3 + 0x87);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar6 + 0x96;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar9 = *(ushort *)(iVar6 + uVar4 * 0xe);
  uVar10 = (ushort)bVar1 * 9 + 2 & 0xff;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(*(code **)(_r_plf_funcs_p + 0xbc));
  iVar6 = _r_ip_funcs_p;
  *(ushort *)(iVar5 + uVar4 * 0xe) = uVar10 * 0xe + 0x1400 | uVar9 & 0x8000;
  (**(code **)(iVar6 + 0x1b0))(param_1,uVar10,8,0,1,1,0,0);
  *(undefined1 *)(iVar3 + 0x92) = 3;
  return;
}

