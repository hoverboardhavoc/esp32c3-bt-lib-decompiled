/*
 * Last changed at upstream commit 688cc3e5db392cd8e80c84c20b86b5ad5a7eff64
 * https://github.com/espressif/esp32c3-bt-lib/commit/688cc3e5db392cd8e80c84c20b86b5ad5a7eff64
 * Upstream date: 2023-04-13 21:28:12 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(8685e3d)
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
  uint uVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  ushort uVar9;
  code *pcVar10;
  ushort uVar11;
  uint uVar12;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar1 = *(ushort *)(iVar4 + 0x74);
  uVar11 = uVar1 & 3;
  uVar5 = ((uint)*(byte *)(iVar4 + 0x87) * 9 & 0xff) + 1 & 0xff;
  uVar9 = 0;
  if (((uVar1 & 3) == 0) && (uVar9 = uVar11, (uVar1 & 4) != 0)) {
    uVar9 = (ushort)(*(short *)(iVar4 + 0x82) == 0);
  }
  if (((*(short *)(iVar4 + 0x82) == 0) && (*(int *)(iVar4 + 0x68) == 0)) && (uVar9 == 0)) {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))
                      (param_1,7,uVar11,(uVar1 >> 5 ^ 1) & 1,uVar1 >> 2 & 1,0,0);
    bVar3 = *(byte *)(iVar4 + 0x87);
    *(undefined1 *)(iVar4 + 0x95) = 0;
    iVar7 = _r_plf_funcs_p;
    *(int *)(iVar4 + 0x6c) = iVar6 + *(int *)(iVar4 + 0x6c);
    iVar7 = (**(code **)(iVar7 + 0xbc))(0x1400,*(code **)(iVar7 + 0xbc));
    cVar8 = '\x01';
    *(undefined2 *)(((uint)bVar3 * 9 + 1) * 0xe + 4 + iVar7) = 0;
  }
  else {
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,7,uVar11,0,0,1,1);
    iVar7 = _r_ip_funcs_p;
    *(int *)(iVar4 + 0x6c) = iVar6 + *(int *)(iVar4 + 0x6c);
    sVar2 = *(short *)(iVar4 + 0x82);
    iVar7 = (**(code **)(iVar7 + 0x1b0))
                      (param_1,uVar5,7,uVar11,(*(ushort *)(iVar4 + 0x74) >> 5 ^ 1) & 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,1,0);
    uVar12 = (uint)*(byte *)(iVar4 + 0x91) << 10;
    *(int *)(iVar4 + 0x6c) = iVar7 + *(int *)(iVar4 + 0x6c);
    if ((uVar12 & 0x30000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar6 = param_1 * 0x5a;
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar7 + iVar6 + 0x26);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar7 + iVar6 + 0x26) = uVar1 & 0x3ff | (ushort)uVar12;
    uVar12 = (uint)*(byte *)(iVar4 + 0x90) << 4;
    if ((uVar12 & 0xffffffcf) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x1bf,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar7 + iVar6 + 4);
    iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    pcVar10 = *(code **)(_r_plf_funcs_p + 0xbc);
    *(ushort *)(iVar7 + iVar6 + 4) = uVar1 & 0xffcf | (ushort)uVar12;
    iVar7 = (*pcVar10)(0x400,pcVar10);
    *(short *)(iVar6 + 0x34 + iVar7) = (short)uVar5 * 0xe + 0x1400;
    cVar8 = '\x01';
    while (sVar2 != 0) {
      bVar3 = *(char *)(iVar4 + 0x87) * '\t' + cVar8 + '\x01';
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,(uint)bVar3,7,0,0,0,1,0);
      iVar7 = _r_plf_funcs_p;
      *(int *)(iVar4 + 0x6c) = iVar6 + *(int *)(iVar4 + 0x6c);
      iVar7 = (**(code **)(iVar7 + 0xbc))(0x1400,*(code **)(iVar7 + 0xbc));
      uVar1 = *(ushort *)(iVar7 + uVar5 * 0xe);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + uVar5 * 0xe) = (ushort)bVar3 * 0xe + 0x1400 | uVar1 & 0x8000;
      uVar5 = (uint)bVar3;
      cVar8 = cVar8 + '\x01';
    }
  }
  *(char *)(iVar4 + 0x92) = cVar8 + '\x01';
  return;
}

