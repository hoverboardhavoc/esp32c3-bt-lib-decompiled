/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_chain_none_construct_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_none_construct_hack(int param_1)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  byte bVar9;
  uint uVar10;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  cVar8 = *(char *)(iVar4 + 0x87) * '\t';
  uVar1 = *(ushort *)(iVar4 + 0x74);
  bVar3 = false;
  uVar5 = (uint)(byte)(cVar8 + 1);
  if ((((uVar1 & 3) == 0) &&
      (bVar3 = (uVar1 & 4) != 0 && *(short *)(iVar4 + 0x82) == 0, *(short *)(iVar4 + 0x82) == 0)) &&
     (iVar6 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar6 + 0x1a) != '\0')) {
    bVar3 = true;
  }
  if (((*(short *)(iVar4 + 0x82) != 0) || (*(int *)(iVar4 + 0x68) != 0)) || (bVar3)) {
    iVar7 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,cVar8,7,0,0,1,1);
    iVar6 = _r_ip_funcs_p;
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar7;
    sVar2 = *(short *)(iVar4 + 0x82);
    iVar6 = (**(code **)(iVar6 + 0x1b0))
                      (param_1,uVar5,7,uVar1 & 3,(*(ushort *)(iVar4 + 0x74) >> 5 ^ 1) & 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,1,0);
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    uVar10 = (uint)*(byte *)(iVar4 + 0x91) << 10;
    if ((uVar10 & 0x30000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = param_1 * 0x5a;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar6 + iVar7 + 0x26);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar7 + 0x26) = uVar1 & 0x3ff | (ushort)uVar10;
    uVar10 = (uint)*(byte *)(iVar4 + 0x90) << 4;
    if ((uVar10 & 0xffffffcf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x1bf,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar6 + iVar7 + 4);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + iVar7 + 4) = uVar1 & 0xffcf | (ushort)uVar10;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(short *)(iVar7 + 0x34 + iVar6) = (short)((uVar5 * 0xe + 0x1400) * 0x10000 >> 0x10);
    cVar8 = '\x01';
    while (sVar2 != 0) {
      bVar9 = *(char *)(iVar4 + 0x87) * '\t' + cVar8 + '\x01';
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,(uint)bVar9,7,0,0,0,1,0);
      *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar6 + uVar5 * 0xe);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(uVar5 * 0xe + iVar6) = (ushort)bVar9 * 0xe + 0x1400 | uVar1 & 0x8000;
      uVar5 = (uint)bVar9;
      cVar8 = cVar8 + '\x01';
    }
  }
  else {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))
                      (param_1,cVar8,7,(*(ushort *)(iVar4 + 0x74) >> 5 ^ 1) & 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,0,0);
    bVar9 = *(byte *)(iVar4 + 0x87);
    *(undefined1 *)(iVar4 + 0x95) = 0;
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    cVar8 = '\x01';
    *(undefined2 *)(((uint)bVar9 * 9 + 1) * 0xe + 4 + iVar6) = 0;
  }
  *(char *)(iVar4 + 0x92) = cVar8 + '\x01';
  return;
}

