/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  code *pcVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar1 = *(ushort *)(iVar3 + 0x74);
  uVar9 = ((uint)*(byte *)(iVar3 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,7,0,0,1,1);
  iVar5 = _r_ip_funcs_p;
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar4;
  iVar5 = (**(code **)(iVar5 + 0x1b0))
                    (param_1,uVar9,7,uVar1 & 3,1,*(ushort *)(iVar3 + 0x74) >> 2 & 1,1,0);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5;
  uVar10 = (uint)*(byte *)(iVar3 + 0x91) << 10;
  if ((uVar10 & 0x30000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar5 = param_1 * 0x5a;
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar4 + iVar5 + 0x26);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar4 + iVar5 + 0x26) = uVar1 & 0x3ff | (ushort)uVar10;
  iVar4 = (*pcVar7)(0x400,pcVar7);
  uVar1 = *(ushort *)(iVar4 + iVar5 + 4);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar4 + iVar5 + 4) = uVar1 & 0xffcf | 0x10;
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar5 + 0x34 + iVar4) = (short)((uVar9 * 0xe + 0x1400) * 0x10000 >> 0x10);
  cVar6 = *(char *)(iVar3 + 0x90);
  if (cVar6 == '\x03') {
    cVar6 = '\x02';
  }
  cVar11 = '\x02';
  iVar5 = (**(code **)(_r_modules_funcs_p + 4))(0xc,cVar6,*(code **)(_r_modules_funcs_p + 4));
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5 + 0x96;
  sVar2 = *(short *)(iVar3 + 0x84);
  uVar10 = (uint)*(byte *)(iVar3 + 0x87) * 9 + 2 & 0xff;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar5 + uVar9 * 0xe);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar5 = _r_ip_funcs_p;
  *(ushort *)(uVar9 * 0xe + iVar4) = (short)uVar10 * 0xe + 0x1400U | uVar1 & 0x8000;
  iVar5 = (**(code **)(iVar5 + 0x1b0))(param_1,uVar10,7,0,1,0,0,0);
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5;
  while (cVar11 = cVar11 + '\x01', sVar2 != 0) {
    bVar8 = *(char *)(iVar3 + 0x87) * '\t' + cVar11;
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,(uint)bVar8,7,0,0,0,0,0);
    *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar5;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar5 + uVar10 * 0xe);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(uVar10 * 0xe + iVar5) = (ushort)bVar8 * 0xe + 0x1400 | uVar1 & 0x8000;
    uVar10 = (uint)bVar8;
  }
  *(char *)(iVar3 + 0x92) = cVar11;
  return;
}

