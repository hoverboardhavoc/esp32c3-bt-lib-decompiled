/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_process_pkt_rx_pkt_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_process_pkt_rx_pkt_check(uint param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  code *pcVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  void *__src;
  undefined1 *puVar11;
  uint uVar12;
  undefined2 uVar13;
  ushort uVar14;
  uint uVar15;
  ushort uVar16;
  ushort uVar17;
  int iVar18;
  uint uVar19;
  short sVar20;
  char cVar21;
  undefined4 auStack_44 [4];
  
  iVar5 = *(int *)(&lld_sync_env + param_1 * 4);
  uVar19 = (uint)*(byte *)(_p_lld_env + 0xd8);
  iVar18 = uVar19 * 0x14;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar14 = *(ushort *)(iVar7 + iVar18 + 2);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  sVar2 = *(short *)(iVar7 + iVar18 + 0x12);
  if ((uVar14 & 0x603d) != 0) {
    iVar5 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar5 + 0x28) & 0x80) != 0) {
      iVar5 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar5 + 0x2c) < 2) {
        r_ble_log_internal_x1(0x20a2000e,uVar19 << 8 | param_1 | (uint)uVar14 << 0x10);
        return;
      }
    }
    return;
  }
  iVar7 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar7 + 0x28) & 0x80) != 0) {
    iVar7 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar7 + 0x2c) < 2) {
      r_ble_log_internal_x1(0x20a2000d,uVar19 << 8 | param_1);
    }
  }
  iVar8 = r_sdk_config_get_opts_ext();
  iVar7 = iVar18 + 4;
  if ((*(uint *)(iVar8 + 0x28) & 0x80) != 0) {
    iVar8 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar8 + 0x2c) < 2) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar14 = *(ushort *)(iVar8 + iVar7);
      uVar9 = r_emi_get_mem_addr_by_offset(sVar2);
      r_ble_log_internal_hex(0x20a2000f,uVar14 >> 8,uVar9);
    }
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  if ((*(ushort *)(iVar8 + iVar7) & 0xf) != 7) {
    r_assert_err(0,"lld_sync.c",0x1cf);
  }
  *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(iVar5 + 0x44);
  *(char *)(iVar5 + 100) = *(char *)(iVar5 + 100) + '\x01';
  if (param_2 == 0) {
    *(char *)(iVar5 + 0x54) = *(char *)(iVar5 + 0x54) + '\x01';
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar14 = *(ushort *)(iVar8 + iVar18 + 0x10);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar17 = uVar14 & 0x3f;
  if (*(ushort *)(iVar8 + iVar7) >> 8 <= uVar17) {
    r_assert_err(0,"lld_sync.c",0x1de);
  }
  cVar21 = '\0';
  if ((uVar14 & 0x3f) != 0) {
    cVar21 = (char)uVar17 + -1;
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar16 = *(ushort *)(iVar8 + iVar7);
  puVar10 = (undefined1 *)r_ke_msg_alloc(0x204,0,0xff,0x1c);
  *puVar10 = (char)param_1;
  uVar16 = (uVar16 >> 8) + ~uVar17 & 0xff;
  *(undefined2 *)(puVar10 + 8) = *(undefined2 *)(iVar5 + 0x4a);
  if (*(char *)(iVar5 + 0x57) == '\0') {
    *(undefined1 *)(iVar5 + 0x57) = 1;
    puVar10[1] = *(undefined1 *)(iVar5 + 0x58);
    puVar10[2] = *(undefined1 *)(iVar5 + 0x59);
    uVar12 = *(uint *)(iVar5 + 0x40);
    *(short *)(puVar10 + 4) = (short)(uVar12 >> 2);
    uVar15 = *(uint *)(iVar5 + 0x44);
    uVar12 = uVar12 >> 1;
    if (uVar12 == 0) {
      r_assert_err(0,"lld_sync.c",0x94);
    }
    *(short *)(puVar10 + 6) = (short)((uVar15 >> 1) % uVar12);
    puVar10[10] = *(undefined1 *)(iVar5 + 0x5a);
    iVar7 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar7 + 0x28) & 0x80) != 0) {
      iVar7 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar7 + 0x2c) < 3) {
        r_ble_log_internal_x2
                  (0x40020003,param_2 << 0x10 | uVar19 << 8 | param_1,*(undefined4 *)(iVar5 + 0x44))
        ;
      }
    }
  }
  else {
    uVar12 = *(uint *)(iVar5 + 0x40) >> 1;
    if (param_2 != 0) {
      uVar15 = *(uint *)(iVar5 + 0x44);
      if (uVar12 == 0) {
        r_assert_err(0,"lld_sync.c",0x94);
      }
      uVar12 = (uVar15 >> 1) % uVar12;
    }
    *(short *)(puVar10 + 6) = (short)uVar12;
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar3 = *(ushort *)(iVar7 + iVar18 + 0x10);
  uVar12 = (uint)uVar3;
  if ((uVar14 & 0x3f) == 0) {
    *(undefined2 *)(iVar5 + 0x62) = 0;
  }
  else {
    sVar20 = 0;
    if ((uVar3 & 0x100) != 0) {
      sVar20 = 6;
    }
    if ((uVar3 & 0x200) != 0) {
      sVar20 = sVar20 + 6;
    }
    if ((uVar3 & 0x400) != 0) {
      sVar20 = sVar20 + 1;
    }
    if ((int)(uVar12 << 0x14) < 0) {
      sVar20 = sVar20 + 2;
    }
    if ((int)(uVar12 << 0x13) < 0) {
      __src = (void *)r_emi_get_mem_addr_by_offset(sVar2 + sVar20);
      memcpy(auStack_44,__src,3);
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      if ((*(ushort *)(iVar7 + iVar18 + 2) >> 9 & 1) == 0) {
        if (*(byte *)(iVar5 + 0x54) < 7) {
          iVar7 = r_lld_calc_aux_rx(iVar5 + 0x24,uVar19,auStack_44[0]);
          uVar13 = 0x101;
          if (iVar7 != 0) goto _L164;
        }
        uVar13 = 2;
      }
      else {
        uVar13 = 0x201;
      }
_L164:
      *(undefined2 *)(iVar5 + 0x62) = uVar13;
      sVar20 = sVar20 + 3;
    }
    else {
      *(undefined2 *)(iVar5 + 0x62) = 0;
    }
    if ((int)(uVar12 << 0x12) < 0) {
      sVar20 = sVar20 + 0x12;
    }
    if ((int)(uVar12 << 0x11) < 0) {
      puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar2 + sVar20);
      sVar20 = sVar20 + 1;
      puVar10[0xb] = *puVar11;
    }
    if (param_2 == 0) {
      puVar10[0x19] = 0;
      puVar10[0x1a] = 0;
    }
    else {
      puVar10[0x19] = ((char)uVar17 + -1) - (char)sVar20;
      puVar10[0x1a] = (char)sVar20;
    }
  }
  pcVar4 = _rwip_rf;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar6 = (*pcVar4)(*(ushort *)(iVar18 + 6 + iVar7) & 0xff);
  puVar10[0xc] = uVar6;
  uVar14 = *(short *)(iVar5 + 0x52) + uVar16;
  *(ushort *)(iVar5 + 0x52) = uVar14;
  if (0x672 < uVar14) {
    uVar16 = (uVar16 + 0x72) - uVar14 & 0xff;
    *(undefined2 *)(iVar5 + 0x62) = 2;
  }
  puVar10[0xe] = (char)uVar16;
  puVar10[0xd] = *(undefined1 *)(iVar5 + 0x62);
  if ((uVar16 != 0) || (puVar10[0x19] != '\0')) {
    *(short *)(puVar10 + 0x10) = sVar2;
    uVar9 = r_emi_get_mem_addr_by_offset(sVar2);
    *(undefined4 *)(puVar10 + 0x14) = uVar9;
    puVar10[0x18] = cVar21;
    bVar1 = *(byte *)(_p_lld_env + 0xd8);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    *(undefined2 *)(iVar7 + (uint)bVar1 * 0x14 + 0x12) = 0;
  }
  if (puVar10[0xd] == '\0') {
    uVar9 = 3;
  }
  else {
    uVar9 = 2;
    if (puVar10[0xd] != '\x02') goto _L133;
  }
  r_lld_sync_scan_dynamic_pti_process(iVar5,uVar9);
_L133:
  r_ke_msg_send(puVar10);
  return;
}

