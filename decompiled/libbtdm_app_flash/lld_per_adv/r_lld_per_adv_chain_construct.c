/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_chain_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_chain_construct(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  short sStack_46;
  undefined2 uStack_44;
  short sStack_42;
  
  iVar2 = *(int *)(&lld_per_adv_env + param_1 * 4);
  uStack_44 = 0;
  sStack_42 = 0;
  uVar3 = (uint)*(byte *)(iVar2 + 0x52) * 9 & 0xff;
  sStack_46 = (ushort)*(byte *)(iVar2 + 0x52) * 0x4b + 0x2000;
  uVar4 = r_lld_ch_idx_get_hack();
  uStack_44 = *(undefined2 *)(iVar2 + 0x4e);
  *(undefined1 *)(iVar2 + 0x57) = uVar4;
  sStack_42 = *(short *)(iVar2 + 0x50);
  *(undefined2 *)(iVar2 + 0x4a) = 0;
  *(undefined4 *)(iVar2 + 0x44) = 0;
  iVar5 = r_lld_per_adv_ext_pkt_prepare
                    (param_1,uVar3,7,0,*(ushort *)(iVar2 + 0x48) >> 6 & 1,0,&sStack_46,&uStack_44);
  uVar8 = (uint)*(byte *)(iVar2 + 0x57) << 10;
  *(int *)(iVar2 + 0x44) = iVar5 + *(int *)(iVar2 + 0x44);
  if ((uVar8 & 0x30000) != 0) {
    r_assert_err(0,"lld_per_adv.c",0x635);
  }
  iVar7 = param_1 * 0x5a;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  uVar1 = *(ushort *)(iVar5 + iVar7 + 0x26);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + iVar7 + 0x26) = uVar1 & 0x3ff | (ushort)uVar8;
  uVar8 = (uint)*(byte *)(iVar2 + 0x55) << 4;
  if ((uVar8 & 0xffffffcf) != 0) {
    r_assert_err(0,"lld_per_adv.c",0x1bf);
  }
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  uVar1 = *(ushort *)(iVar5 + iVar7 + 4);
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar5 + iVar7 + 4) = uVar1 & 0xffcf | (ushort)uVar8;
  iVar5 = r_emi_get_mem_addr_by_offset(0x400);
  cVar9 = '\0';
  *(short *)(iVar7 + 0x34 + iVar5) = (short)uVar3 * 0xe + 0x1400;
  while( true ) {
    cVar9 = cVar9 + '\x01';
    if (sStack_42 == 0) break;
    iVar5 = uVar3 * 0xe;
    bVar6 = *(char *)(iVar2 + 0x52) * '\t' + cVar9;
    uVar3 = (uint)bVar6;
    iVar7 = r_lld_per_adv_ext_pkt_prepare
                      (param_1,uVar3,7,0,*(ushort *)(iVar2 + 0x48) >> 6 & 1,0,&sStack_46,&uStack_44)
    ;
    *(int *)(iVar2 + 0x44) = iVar7 + *(int *)(iVar2 + 0x44);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar1 = *(ushort *)(iVar7 + iVar5);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar5 + iVar7) = (ushort)bVar6 * 0xe + 0x1400 | uVar1 & 0x8000;
  }
  uVar3 = *(int *)(iVar2 + 0x44) * 2 + (uint)_sdk_cfg_priv_opts;
  *(char *)(iVar2 + 0x58) = cVar9;
  if (uVar3 < 0x272) {
    uVar3 = 0x272;
  }
  *(uint *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x10) = uVar3;
  return;
}

