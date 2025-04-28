/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  cVar7 = *(char *)(iVar4 + 0x87) * '\t';
  uVar1 = *(ushort *)(iVar4 + 0x74);
  bVar3 = false;
  uVar5 = (uint)(byte)(cVar7 + 1);
  if ((((uVar1 & 3) == 0) &&
      (bVar3 = (uVar1 & 4) != 0 && *(short *)(iVar4 + 0x82) == 0, *(short *)(iVar4 + 0x82) == 0)) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(char *)(iVar6 + 0x1a) != '\0')) {
    bVar3 = true;
  }
  if (((*(short *)(iVar4 + 0x82) != 0) || (*(int *)(iVar4 + 0x68) != 0)) || (bVar3)) {
    iVar6 = r_lld_adv_ext_pkt_prepare(param_1,cVar7,7,0,0,1,1);
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    sVar2 = *(short *)(iVar4 + 0x82);
    iVar6 = r_lld_adv_ext_pkt_prepare
                      (param_1,uVar5,7,uVar1 & 3,(*(ushort *)(iVar4 + 0x74) >> 5 ^ 1) & 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,1,0);
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    uVar10 = (uint)*(byte *)(iVar4 + 0x91) << 10;
    if ((uVar10 & 0x30000) != 0) {
      r_assert_err(0,0x10000,0x635);
    }
    iVar9 = param_1 * 0x5a;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *(ushort *)(iVar6 + iVar9 + 0x26);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar9 + 0x26) = uVar1 & 0x3ff | (ushort)uVar10;
    uVar10 = (uint)*(byte *)(iVar4 + 0x90) << 4;
    if ((uVar10 & 0xffffffcf) != 0) {
      r_assert_err(0,0x10000,0x1bf);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar1 = *(ushort *)(iVar6 + iVar9 + 4);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar9 + 4) = uVar1 & 0xffcf | (ushort)uVar10;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(short *)(iVar9 + 0x34 + iVar6) = (short)((uVar5 * 0xe + 0x1400) * 0x10000 >> 0x10);
    cVar7 = '\x01';
    while (sVar2 != 0) {
      iVar6 = uVar5 * 0xe;
      bVar8 = *(char *)(iVar4 + 0x87) * '\t' + cVar7 + '\x01';
      uVar5 = (uint)bVar8;
      iVar9 = r_lld_adv_ext_pkt_prepare(param_1,uVar5,7,0,0,0,1,0);
      *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar9;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar1 = *(ushort *)(iVar9 + iVar6);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar6 + iVar9) = (ushort)bVar8 * 0xe + 0x1400 | uVar1 & 0x8000;
      cVar7 = cVar7 + '\x01';
    }
  }
  else {
    iVar6 = r_lld_adv_ext_pkt_prepare
                      (param_1,7,(*(ushort *)(iVar4 + 0x74) >> 5 ^ 1) & 1,
                       *(ushort *)(iVar4 + 0x74) >> 2 & 1,0,0);
    bVar8 = *(byte *)(iVar4 + 0x87);
    *(undefined1 *)(iVar4 + 0x95) = 0;
    *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    cVar7 = '\x01';
    *(undefined2 *)(((uint)bVar8 * 9 + 1) * 0xe + 4 + iVar6) = 0;
  }
  *(char *)(iVar4 + 0x92) = cVar7 + '\x01';
  return;
}

