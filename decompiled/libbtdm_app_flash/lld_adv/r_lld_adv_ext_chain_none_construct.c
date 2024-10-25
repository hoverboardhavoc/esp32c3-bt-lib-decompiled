/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_chain_none_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_ext_chain_none_construct(int param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  byte bVar7;
  ushort uVar8;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  cVar6 = *(char *)(iVar3 + 0x87) * '\t';
  uVar1 = *(ushort *)(iVar3 + 0x74);
  uVar8 = uVar1 & 3;
  uVar9 = 0;
  bVar7 = cVar6 + 1;
  uVar4 = (uint)bVar7;
  if ((uVar1 & 3) == 0) {
    uVar9 = uVar8;
    if ((uVar1 & 4) != 0) {
      uVar9 = (ushort)(*(short *)(iVar3 + 0x82) == 0);
    }
    if ((*(short *)(iVar3 + 0x82) == 0) &&
       (iVar5 = r_sdk_config_get_opts_ext(), *(char *)(iVar5 + 0x1a) != '\0')) {
      uVar9 = 1;
    }
  }
  if (((*(short *)(iVar3 + 0x82) == 0) && (*(int *)(iVar3 + 0x68) == 0)) && (uVar9 == 0)) {
    iVar5 = r_lld_adv_ext_pkt_prepare
                      (param_1,7,uVar8,(*(ushort *)(iVar3 + 0x74) >> 5 ^ 1) & 1,
                       *(ushort *)(iVar3 + 0x74) >> 2 & 1,0,0);
    bVar7 = *(byte *)(iVar3 + 0x87);
    *(undefined1 *)(iVar3 + 0x95) = 0;
    *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    cVar6 = '\x01';
    *(undefined2 *)(((uint)bVar7 * 9 + 1) * 0xe + 4 + iVar5) = 0;
  }
  else {
    iVar5 = r_lld_adv_ext_pkt_prepare(param_1,cVar6,7,uVar8,0,0,1,1);
    *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
    sVar2 = *(short *)(iVar3 + 0x82);
    iVar5 = r_lld_adv_ext_pkt_prepare
                      (param_1,uVar4,7,uVar8,(*(ushort *)(iVar3 + 0x74) >> 5 ^ 1) & 1,
                       *(ushort *)(iVar3 + 0x74) >> 2 & 1,1,0);
    uVar11 = (uint)*(byte *)(iVar3 + 0x91) << 10;
    *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
    if ((uVar11 & 0x30000) != 0) {
      r_assert_err(0,"lld_adv.c",0x635);
    }
    iVar10 = param_1 * 0x5a;
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *(ushort *)(iVar5 + iVar10 + 0x26);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar10 + 0x26) = uVar1 & 0x3ff | (ushort)uVar11;
    uVar11 = (uint)*(byte *)(iVar3 + 0x90) << 4;
    if ((uVar11 & 0xffffffcf) != 0) {
      r_assert_err(0,"lld_adv.c",0x1bf);
    }
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *(ushort *)(iVar5 + iVar10 + 4);
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar10 + 4) = uVar1 & 0xffcf | (ushort)uVar11;
    iVar5 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar10 + 0x34 + iVar5) = (ushort)bVar7 * 0xe + 0x1400;
    cVar6 = '\x01';
    while (sVar2 != 0) {
      bVar7 = *(char *)(iVar3 + 0x87) * '\t' + cVar6 + '\x01';
      iVar5 = uVar4 * 0xe;
      uVar4 = (uint)bVar7;
      iVar10 = r_lld_adv_ext_pkt_prepare(param_1,uVar4,7,0,0,0,1,0);
      *(int *)(iVar3 + 0x6c) = iVar10 + *(int *)(iVar3 + 0x6c);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar10 + iVar5);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar5 + iVar10) = (ushort)bVar7 * 0xe + 0x1400 | uVar1 & 0x8000;
      cVar6 = cVar6 + '\x01';
    }
  }
  *(char *)(iVar3 + 0x92) = cVar6 + '\x01';
  return;
}

