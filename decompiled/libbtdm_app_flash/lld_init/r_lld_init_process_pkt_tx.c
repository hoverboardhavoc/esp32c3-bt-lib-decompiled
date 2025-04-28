/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_init.o -> r_lld_init_process_pkt_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_tx(int param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  undefined1 *__s;
  undefined4 uVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  iVar9 = _lld_init_env;
  iVar12 = *(int *)(param_1 * 4 + _lld_init_env);
  iVar11 = ((uint)*(byte *)(_lld_init_env + 0x2c) * 9 & 0xff) * 0xe;
  if (*(char *)(_lld_init_env + 0x50) != '\0') {
    iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
    if ((*(short *)(iVar5 + iVar11) < 0) && (iVar5 = r_lld_init_evt_end_type_get(), iVar5 == 0)) {
      __s = (undefined1 *)r_ke_msg_alloc(0x209,0,0xff,0x38);
      bVar1 = (&co_rate_to_phy)[*(byte *)(iVar9 + 0x4e)];
      uVar6 = r_lld_init_process_pkt_tx_cal_con_timestamp(param_1);
      memset(__s,0,0x38);
      __s[0x20] = *(byte *)(iVar9 + 0x33) & 1;
      uVar10 = (uint)*(ushort *)(iVar9 + 0x4c);
      if (uVar10 == 0) {
        memcpy(__s + 0xe,(void *)(iVar12 + 0x32),6);
      }
      else {
        pvVar7 = (void *)r_emi_get_mem_addr_by_offset(uVar10 + 0x18 & 0xffff);
        memcpy(__s + 0xe,pvVar7,6);
        iVar5 = ((uVar10 - 0xc60) / 0x34 & 0xff) * 0x34;
        if ((*(byte *)(iVar9 + 0x32) & 2) != 0) {
          iVar8 = r_emi_get_mem_addr_by_offset(0xc60);
          if ((*(ushort *)(iVar8 + iVar5) >> 7 & 1) != 0) {
            pvVar7 = (void *)r_emi_get_mem_addr_by_offset(*(short *)(iVar9 + 0x4c) + 0x2e);
            memcpy(__s + 2,pvVar7,6);
          }
        }
        iVar8 = r_emi_get_mem_addr_by_offset(0xc60);
        if ((*(ushort *)(iVar8 + iVar5) >> 3 & 1) != 0) {
          pvVar7 = (void *)r_emi_get_mem_addr_by_offset(*(short *)(iVar9 + 0x4c) + 0x12);
          memcpy(__s + 8,pvVar7,6);
          iVar8 = r_emi_get_mem_addr_by_offset(0xc60);
          __s[0x20] = (byte)*(undefined2 *)(iVar8 + iVar5) & 1 | 2;
        }
      }
      memcpy(__s + 0x14,(void *)(iVar9 + 0x34),4);
      iVar5 = (uint)bVar1 * 10 + iVar9;
      *(undefined2 *)(__s + 0x18) = *(undefined2 *)(iVar5 + 2);
      *(undefined2 *)(__s + 0x1a) = *(undefined2 *)(iVar5 + 4);
      memcpy(__s + 0x21,(void *)(iVar9 + 0x2d),5);
      __s[0x26] = *(undefined1 *)(iVar5 + 10);
      __s[0x27] = *(undefined1 *)(iVar9 + 0x4e);
      *(undefined2 *)(__s + 0x28) = *(undefined2 *)(iVar5 + 6);
      *(undefined2 *)(__s + 0x2a) = *(undefined2 *)(iVar5 + 8);
      memcpy(__s + 0x2c,(void *)(iVar9 + 0x38),3);
      __s[0x2f] = *(undefined1 *)(iVar9 + 0x3b);
      __s[0x30] = *(undefined1 *)(iVar9 + 0x3c);
      __s[0x31] = *(undefined1 *)(iVar9 + 0x3d);
      sVar2 = *(short *)(iVar12 + 0x38);
      sVar3 = *(short *)(iVar12 + 0x3a);
      *(undefined4 *)(__s + 0x1c) = uVar6;
      __s[0x33] = sVar2 != sVar3;
      __s[0x34] = *(undefined1 *)(iVar9 + 0x58);
      __s[1] = 1;
      *__s = *(undefined1 *)(iVar9 + 0x2c);
      *(undefined1 **)(iVar9 + 8) = __s;
      r_lld_init_end();
      goto _L217;
    }
  }
  *(undefined1 *)(iVar9 + 0x50) = 0;
_L217:
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar4 = *(ushort *)(iVar9 + iVar11);
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + iVar11) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
  return;
}

