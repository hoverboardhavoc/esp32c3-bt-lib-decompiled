/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_chain_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_chain_construct(int param_1)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  short sStack_46;
  undefined2 uStack_44;
  short sStack_42;
  
  iVar3 = *(int *)(&lld_per_adv_env + param_1 * 4);
  uStack_44 = 0;
  sStack_42 = 0;
  uVar4 = (uint)*(byte *)(iVar3 + 0x52) * 9 & 0xff;
  sStack_46 = (ushort)*(byte *)(iVar3 + 0x52) * 0x4b + 0x2000;
  uVar5 = (**(code **)(_r_ip_funcs_p + 0x230))(*(code **)(_r_ip_funcs_p + 0x230));
  uStack_44 = *(undefined2 *)(iVar3 + 0x4e);
  *(undefined1 *)(iVar3 + 0x57) = uVar5;
  sStack_42 = *(short *)(iVar3 + 0x50);
  *(undefined2 *)(iVar3 + 0x4a) = 0;
  *(undefined4 *)(iVar3 + 0x44) = 0;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x2e8))
                    (param_1,uVar4,7,0,*(ushort *)(iVar3 + 0x48) >> 6 & 1,0,&sStack_46,&uStack_44);
  uVar9 = (uint)*(byte *)(iVar3 + 0x57) << 10;
  *(int *)(iVar3 + 0x44) = iVar6 + *(int *)(iVar3 + 0x44);
  if ((uVar9 & 0x30000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = param_1 * 0x5a;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar6 + iVar8 + 0x26);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar8 + 0x26) = uVar1 & 0x3ff | (ushort)uVar9;
  uVar9 = (uint)*(byte *)(iVar3 + 0x55) << 4;
  if ((uVar9 & 0xffffffcf) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_per_adv.c",0x1bf,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar6 + iVar8 + 4);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar8 + 4) = uVar1 & 0xffcf | (ushort)uVar9;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar6 + iVar8 + 0x34) = (short)uVar4 * 0xe + 0x1400;
  cVar2 = '\0';
  while( true ) {
    cVar2 = cVar2 + '\x01';
    if (sStack_42 == 0) break;
    bVar7 = *(char *)(iVar3 + 0x52) * '\t' + cVar2;
    iVar8 = (**(code **)(_r_ip_funcs_p + 0x2e8))
                      (param_1,(uint)bVar7,7,0,*(ushort *)(iVar3 + 0x48) >> 6 & 1,0,&sStack_46,
                       &uStack_44);
    iVar6 = _r_plf_funcs_p;
    *(int *)(iVar3 + 0x44) = iVar8 + *(int *)(iVar3 + 0x44);
    iVar6 = (**(code **)(iVar6 + 0xbc))(0x1400,*(code **)(iVar6 + 0xbc));
    uVar1 = *(ushort *)(iVar6 + uVar4 * 0xe);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + uVar4 * 0xe) = (ushort)bVar7 * 0xe + 0x1400 | uVar1 & 0x8000;
    uVar4 = (uint)bVar7;
  }
  uVar4 = *(int *)(iVar3 + 0x44) * 2 + (uint)_sdk_cfg_priv_opts;
  *(char *)(iVar3 + 0x58) = cVar2;
  if (uVar4 < 0x272) {
    uVar4 = 0x272;
  }
  *(uint *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x10) = uVar4;
  return;
}

