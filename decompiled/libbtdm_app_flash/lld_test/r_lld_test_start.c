/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_test_start(char *param_1)

{
  char cVar1;
  byte bVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  void *__s;
  undefined4 uVar6;
  int iVar7;
  undefined2 *puVar8;
  ushort *puVar9;
  int iVar10;
  void *__dest;
  ushort uVar11;
  byte bStack_122;
  byte bStack_121;
  byte abStack_120 [256];
  
  if (_lld_test_env != (void *)0x0) {
    return 0xc;
  }
  __s = (void *)r_ke_malloc(0x2c,0);
  _lld_test_env = __s;
  if (__s == (void *)0x0) {
    r_assert_err("lld_test.c",0x31b);
    return 0xc;
  }
  uVar6 = r_lld_read_clock();
  memset(__s,0,0x2c);
  *(undefined4 *)((int)__s + 0x20) = 0x10000;
  *(code **)((int)__s + 0x18) = r_lld_test_evt_start_cbk;
  bVar2 = DAT_0001101d;
  *(code *)((int)__s + 0x16) = r_emi_get_mem_addr_by_offset;
  *(undefined4 *)((int)__s + 0x10) = 0x9c4;
  *(ushort *)((int)__s + 0x14) = bVar2 & 0xf | 0x6000;
  cVar1 = *param_1;
  *(char *)((int)__s + 0x26) = cVar1;
  *(char *)((int)__s + 0x27) = param_1[1];
  if (cVar1 == '\0') {
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff | 0x4000;
    _DAT_600310d0 = _DAT_600310d0 & 0xf7ffffff | 0x8000000;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x4a) = 0;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x4c) = 0;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x4e) = 0;
    bStack_121 = 0;
    abStack_120[0] = 0;
    r_bt_rma_get_ant_by_act(0x1d,0,&bStack_121,abStack_120);
    puVar8 = (undefined2 *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar8 = 0x1d;
    uVar4 = (uint)bStack_121;
    if ((uVar4 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,"lld_test.c",0x82);
    }
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = *puVar9;
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar9 = uVar11 & 0xff7f | (ushort)(uVar4 << 7);
    uVar4 = (uint)abStack_120[0];
    if ((uVar4 << 6 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_test.c",0x8e);
    }
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = *puVar9;
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar9 = uVar11 & 0xffbf | (ushort)(uVar4 << 6);
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x1a) = 0x8026;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x28) = 0xff;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    pcVar3 = _rwip_rf;
    *(undefined2 *)(iVar7 + 0x2a) = 0;
    (*pcVar3)(0,pcVar3);
  }
  else if (cVar1 == '\x01') {
    *(char *)((int)__s + 0x28) = param_1[2];
    *(char *)((int)__s + 0x29) = param_1[3];
    iVar7 = r_ble_util_buf_acl_tx_alloc(0xff);
    if (iVar7 == 0) {
      r_lld_test_cleanup();
      return 7;
    }
    *(short *)((int)__s + 0x24) = (short)iVar7;
    iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
    *(short *)(iVar10 + 4) = (short)iVar7;
    _DAT_60031000 = _DAT_60031000 & 0xffffbfff | 0x4000;
    _DAT_600310d0 = _DAT_600310d0 & 0xfffff7ff | 0x800;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x44) = 0;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x46) = 0;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x48) = 0;
    uVar4 = (uint)(byte)param_1[3];
    if (uVar4 < 8) {
      uVar5 = 1 << (uVar4 & 0x1f);
      if ((uVar5 & 0xf6) == 0) {
        if ((uVar5 & 9) != 0) {
          _DAT_600310d0 = (uVar4 & 1) << 0xd | _DAT_600310d0 & 0xffffcfff | 0x1000;
        }
      }
      else {
        switch(uVar4 - 1 & 0xff) {
        case 0:
          iVar7 = 0xf0;
          break;
        case 1:
          iVar7 = 0xaa;
          break;
        default:
          iVar7 = 0;
          break;
        case 3:
          iVar7 = 0xff;
          break;
        case 5:
          iVar7 = 0xf;
          break;
        case 6:
          iVar7 = 0x55;
        }
        bVar2 = param_1[2];
        memset(abStack_120,iVar7,(uint)bVar2);
        __dest = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)((int)__s + 0x24));
        memcpy(__dest,abStack_120,(uint)bVar2);
        _DAT_600310d0 = _DAT_600310d0 & 0xffffefff;
      }
    }
    else {
      r_assert_err(0,"lld_test.c",0x2c3);
    }
    bVar2 = param_1[3];
    cVar1 = param_1[2];
    if ((bVar2 & 0xf0) != 0) {
      r_assert_err(0,"lld_test.c",0x126);
    }
    iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar7 + 2) = CONCAT11(cVar1,bVar2);
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x1400);
    uVar11 = *puVar9;
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x1400);
    *puVar9 = uVar11 & 0x7fff;
    iVar7 = r_emi_get_mem_addr_by_offset(0x400);
    *(undefined2 *)(iVar7 + 0x1c) = 0x1400;
    bStack_122 = 0;
    bStack_121 = 0;
    r_bt_rma_get_ant_by_act(0x1c,0,&bStack_122,&bStack_121);
    puVar8 = (undefined2 *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar8 = 0x1c;
    uVar4 = (uint)bStack_122;
    if ((uVar4 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,"lld_test.c",0x82);
    }
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = *puVar9;
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar9 = uVar11 & 0xff7f | (ushort)(uVar4 << 7);
    uVar4 = (uint)bStack_121;
    if ((uVar4 << 6 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_test.c",0x8e);
    }
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    uVar11 = *puVar9;
    puVar9 = (ushort *)r_emi_get_mem_addr_by_offset(0x400);
    *puVar9 = uVar11 & 0xffbf | (ushort)(uVar4 << 6);
    r_lld_test_set_tx_power(0,0x1c);
  }
  else {
    r_assert_err(0,"lld_test.c",0x2ed);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar7 + 0xc) = 0x4129;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar7 + 0xe) = 0x7176;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar7 + 0x10) = 0x5555;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar7 + 0x12) = 0x55;
  uVar4 = r_lld_test_freq2chnl(param_1[1]);
  if ((uVar4 & 0xffffffc0) != 0) {
    r_assert_err(0,"lld_test.c",0x3cf);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  uVar11 = *(ushort *)(iVar7 + 0x16);
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar7 + 0x16) = uVar11 & 0xffc0 | (ushort)uVar4;
  if (*param_1 == '\x01') {
    uVar11 = (byte)param_1[4] - 1 & 0xff;
  }
  else {
    if (*param_1 == '\0') {
      uVar4 = (byte)param_1[4] - 1 & 0xff;
      uVar11 = 0;
      goto _L122;
    }
    uVar11 = 0;
  }
  uVar4 = 0;
_L122:
  if ((uVar4 << 2 & 0xfffffff3) != 0) {
    r_assert_err(0,"lld_test.c",399);
  }
  if ((uVar11 & 0xfffc) != 0) {
    r_assert_err(0,"lld_test.c",400);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar7 + 4) = (ushort)(uVar4 << 2) | uVar11 | 0x1000;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar7 + 0x4a) = 0;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar7 + 0x4c) = 0;
  iVar7 = r_emi_get_mem_addr_by_offset(0x400);
  *(undefined2 *)(iVar7 + 0x4e) = 0;
  *(undefined4 *)((int)__s + 4) = uVar6;
  iVar7 = r_sch_arb_insert(__s);
  if (iVar7 != 0) {
    r_assert_err(0,"lld_test.c",0x314);
    return 0;
  }
  *(undefined1 *)((int)__s + 0x2a) = 0;
  return 0;
}

