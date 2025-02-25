/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> llc_llcp.o -> r_llc_llcp_tx_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_llcp_tx_check(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *__dest;
  int iVar5;
  uint uVar6;
  byte bVar7;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  if ((*(ushort *)(iVar3 + 0x42) & 2) == 0) {
    bVar1 = true;
    for (piVar2 = *(int **)(iVar3 + 0x28); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      uVar6 = (int)(uint)*(byte *)(iVar3 + 0x44) >> 2 & 3;
      bVar7 = (&DAT_0001083e)[(uint)*(byte *)((int)piVar2 + 9) * 0xc];
      if (uVar6 == 2) {
        bVar7 = bVar7 >> 1;
      }
      else if (uVar6 == 3) {
        bVar7 = bVar7 >> 3;
      }
      else if (uVar6 == 1) {
        bVar7 = bVar7 >> 2;
      }
      if ((bVar7 & 1) != 0) {
        iVar4 = r_ble_util_buf_llcp_tx_alloc();
        if (iVar4 == 0) {
          r_assert_err("llc_llcp.c",0x385);
        }
        bVar7 = *(byte *)(piVar2 + 2);
        __dest = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar4 + 4));
        memcpy(__dest,(void *)((int)piVar2 + 9),(uint)bVar7);
        *(undefined1 *)(iVar4 + 6) = *(undefined1 *)(piVar2 + 2);
        *(ushort *)(iVar3 + 0x42) = *(ushort *)(iVar3 + 0x42) | 2;
        iVar5 = r_lld_con_llcp_tx(param_1,iVar4);
        if (iVar5 == 0) {
          if (bVar1) {
            return;
          }
          r_co_list_extract(iVar3 + 0x28,piVar2);
          r_co_list_push_front(iVar3 + 0x28,piVar2);
          return;
        }
        r_ble_util_buf_llcp_tx_free(*(undefined2 *)(iVar4 + 4));
        return;
      }
      bVar1 = false;
    }
  }
  return;
}

