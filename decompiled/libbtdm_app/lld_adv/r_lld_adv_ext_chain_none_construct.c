/*
 * Last changed at upstream commit 9d40b3bc0ac38d72b66fe0f612a8dda64c7330d7
 * https://github.com/espressif/esp32c3-bt-lib/commit/9d40b3bc0ac38d72b66fe0f612a8dda64c7330d7
 * Upstream date: 2024-01-12 16:10:16 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(9359a4d)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_chain_none_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_none_construct(int param_1)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  code *pcVar8;
  ushort uVar9;
  ushort uVar10;
  uint uVar11;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  cVar7 = *(char *)(iVar4 + 0x87) * '\t';
  uVar1 = *(ushort *)(iVar4 + 0x74);
  uVar9 = uVar1 & 3;
  uVar10 = 0;
  bVar3 = cVar7 + 1;
  if ((uVar1 & 3) == 0) {
    uVar10 = uVar9;
    if ((uVar1 & 4) != 0) {
      uVar10 = (ushort)(*(short *)(iVar4 + 0x82) == 0);
    }
    if ((*(short *)(iVar4 + 0x82) == 0) &&
       (iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
       *(char *)(iVar5 + 0x1a) != '\0')) {
      uVar10 = 1;
    }
  }
  if (((*(short *)(iVar4 + 0x82) == 0) && (*(int *)(iVar4 + 0x68) == 0)) && (uVar10 == 0)) {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))
                      (param_1,cVar7,7,uVar9,(*(ushort *)(iVar4 + 0x74) >> 5 ^ 1) & 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,0,0);
    bVar3 = *(byte *)(iVar4 + 0x87);
    *(undefined1 *)(iVar4 + 0x95) = 0;
    iVar5 = _r_plf_funcs_p;
    *(int *)(iVar4 + 0x6c) = iVar6 + *(int *)(iVar4 + 0x6c);
    iVar5 = (**(code **)(iVar5 + 0xbc))(0x1400,*(code **)(iVar5 + 0xbc));
    cVar7 = '\x01';
    *(undefined2 *)(((uint)bVar3 * 9 + 1) * 0xe + 4 + iVar5) = 0;
  }
  else {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,cVar7,7,uVar9,0,0,1,1);
    iVar5 = _r_ip_funcs_p;
    *(int *)(iVar4 + 0x6c) = iVar6 + *(int *)(iVar4 + 0x6c);
    sVar2 = *(short *)(iVar4 + 0x82);
    iVar5 = (**(code **)(iVar5 + 0x1b0))
                      (param_1,(uint)bVar3,7,uVar9,(*(ushort *)(iVar4 + 0x74) >> 5 ^ 1) & 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,1,0);
    uVar11 = (uint)*(byte *)(iVar4 + 0x91) << 10;
    *(int *)(iVar4 + 0x6c) = iVar5 + *(int *)(iVar4 + 0x6c);
    if ((uVar11 & 0x30000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = param_1 * 0x5a;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar5 + iVar6 + 0x26);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar5 + iVar6 + 0x26) = uVar1 & 0x3ff | (ushort)uVar11;
    uVar11 = (uint)*(byte *)(iVar4 + 0x90) << 4;
    if ((uVar11 & 0xffffffcf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x1bf,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar5 + iVar6 + 4);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar8 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar5 + iVar6 + 4) = uVar1 & 0xffcf | (ushort)uVar11;
    iVar5 = (*pcVar8)(0x400,pcVar8);
    *(ushort *)(iVar6 + 0x34 + iVar5) = (ushort)bVar3 * 0xe + 0x1400;
    uVar11 = (uint)bVar3;
    cVar7 = '\x01';
    while (sVar2 != 0) {
      bVar3 = *(char *)(iVar4 + 0x87) * '\t' + cVar7 + '\x01';
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,(uint)bVar3,7,0,0,0,1,0);
      iVar5 = _r_plf_funcs_p;
      *(int *)(iVar4 + 0x6c) = iVar6 + *(int *)(iVar4 + 0x6c);
      iVar5 = (**(code **)(iVar5 + 0xbc))(0x1400,*(code **)(iVar5 + 0xbc));
      uVar1 = *(ushort *)(iVar5 + uVar11 * 0xe);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar5 + uVar11 * 0xe) = (ushort)bVar3 * 0xe + 0x1400 | uVar1 & 0x8000;
      uVar11 = (uint)bVar3;
      cVar7 = cVar7 + '\x01';
    }
  }
  *(char *)(iVar4 + 0x92) = cVar7 + '\x01';
  return;
}

